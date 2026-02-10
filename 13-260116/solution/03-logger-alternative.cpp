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

// TODO START
struct log_message_formatter : private noncopyable {
    virtual ~log_message_formatter() = default;

    virtual std::string format(const std::string& s) const = 0;
};

struct logger : private noncopyable {
protected:
    std::unique_ptr<log_message_formatter> m_formatter;

public: 
    logger(std::unique_ptr<log_message_formatter>&& formatter)
        : m_formatter{std::move(formatter)} {
    }

    virtual void log(const std::string& message) = 0;

    virtual ~logger() = default;
};

struct cout_logger : public logger {
    cout_logger(std::unique_ptr<log_message_formatter>&& formatter)
        : logger(std::move(formatter)) {
    }

    void log(const std::string& message) override {
        std::cout << m_formatter->format(message) << '\n';
    }
};

struct cerr_logger : public logger {
    cerr_logger(std::unique_ptr<log_message_formatter>&& formatter)
        : logger(std::move(formatter)) {
    }

    void log(const std::string& message) override {
        std::cerr << m_formatter->format(message) << '\n';
    }
};

struct file_logger : public logger {
private:
    std::ofstream m_ofile;

public:
    file_logger(
        std::unique_ptr<log_message_formatter>&& formatter,
        const std::string &filename)
        : logger(std::move(formatter)), m_ofile(filename) {
    }

    void log(const std::string& message) override {
        m_ofile << m_formatter->format(message) << '\n';
    }
};

struct log_identity_formatter : public log_message_formatter {
    std::string format(const std::string& s) const override {
        return s;
    }
};

struct log_tagged_formatter : public log_message_formatter {
private:
    std::string tag;
public:
    std::string format(const std::string &message) const override {
        return "[" + tag + "] " + message;
    }

    log_tagged_formatter(std::string tag_)
        : tag(std::move(tag_)) {}
};
// TODO END

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
        cout_logger l(std::make_unique<log_identity_formatter>());  // TODO
        test_plain_cout(l);
    }
    {
        cout_logger l(std::make_unique<log_tagged_formatter>("MYTAG"));  // TODO
        test_tagged_cout(l);
    }
    {
        cerr_logger l(std::make_unique<log_identity_formatter>());  // TODO
        test_plain_cerr(l);
    }
    {
        cerr_logger l(std::make_unique<log_tagged_formatter>("MYTAG"));  // TODO
        test_tagged_cerr(l);
    }
    {
        file_logger l(std::make_unique<log_identity_formatter>(), "03-logger-plain.out");  // TODO
        test_plain_file(l);
    }
    {
        file_logger l((std::make_unique<log_tagged_formatter>("MYTAG")), "03-logger-tagged.out");  // TODO
        test_tagged_file(l);
    }
}
