#include <cassert>
#include <fstream>
#include <iostream>
#include <memory>
#include <utility>

struct noncopyable {
    noncopyable() = default;
    noncopyable(const noncopyable &) = delete;
    noncopyable(noncopyable &&) = delete;
    noncopyable &operator=(const noncopyable &) = delete;
    noncopyable &operator=(noncopyable &&) = delete;
};

struct log_printer : private noncopyable {
    virtual ~log_printer() = default;
    virtual void print(const std::string &s) = 0;
};

struct cout_log_printer : log_printer {
    void print(const std::string &s) override {
        std::cout << s << "\n";
    }
};

struct cerr_log_printer : log_printer {
    void print(const std::string &s) override {
        std::cerr << s << "\n";
    }
};

struct file_log_printer : log_printer {
private:
    std::ofstream out;
public:
    explicit file_log_printer(const std::string &filename) : out(filename) {
        assert(out);
    }
    void print(const std::string &s) override {
        out << s << "\n";
    }
};

struct logger : private noncopyable {
protected:
    std::unique_ptr<log_printer> printer;

public:
    explicit logger(std::unique_ptr<log_printer> printer_) : printer(std::move(printer_)) {}
    virtual ~logger() = default;
    virtual void log(const std::string &message) = 0;
};

struct plain_logger : logger {
    using logger::logger;
    void log(const std::string &message) override {
        printer->print(message);
    }
};

struct tagged_logger : logger {
private:
    std::string tag;
public:
    explicit tagged_logger(std::unique_ptr<log_printer> printer_, std::string tag_)
        : logger(std::move(printer_))
        , tag(std::move(tag_)) {}
    void log(const std::string &message) override {
        printer->print("[" + tag + "] " + message);
    }
};

void test_plain_cout(logger &l) {
    l.log("This should go to cout with no tag (1/2)");
    l.log("This should go to cout with no tag (2/2)");
}

void test_tagged_cout(logger &l) {
    l.log("This should go to cout with a tag (1/2)");
    l.log("This should go to cout with a tag (2/2)");
}

void test_plain_cerr(logger &l) {
    l.log("This should go to cerr with no tag (1/2)");
    l.log("This should go to cerr with no tag (2/2)");
}

void test_tagged_cerr(logger &l) {
    l.log("This should go to cerr with a tag (1/2)");
    l.log("This should go to cerr with a tag (2/2)");
}

void test_plain_file(logger &l) {
    l.log("This should go to file with no tag (1/2)");
    l.log("This should go to file with no tag (2/2)");
}

void test_tagged_file(logger &l) {
    l.log("This should go to file with a tag (1/2)");
    l.log("This should go to file with a tag (2/2)");
}

int main() {
    {
        plain_logger l(std::make_unique<cout_log_printer>());
        test_plain_cout(l);
    }
    {
        tagged_logger l(std::make_unique<cout_log_printer>(), "MYTAG");
        test_tagged_cout(l);
    }
    {
        plain_logger l(std::make_unique<cerr_log_printer>());
        test_plain_cerr(l);
    }
    {
        tagged_logger l(std::make_unique<cerr_log_printer>(), "MYTAG");
        test_tagged_cerr(l);
    }
    {
        plain_logger l(std::make_unique<file_log_printer>("03-logger-plain.out"));
        test_plain_file(l);
    }
    {
        tagged_logger l(std::make_unique<file_log_printer>("03-logger-tagged.out"), "MYTAG");
        test_tagged_file(l);
    }
}
