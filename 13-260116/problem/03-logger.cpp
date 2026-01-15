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
struct logger : private noncopyable {
    explicit logger() = default;
    virtual ~logger() = default;
    virtual void log(const std::string &message) {
        std::cout << message << "\n";
    }
};

struct tagged_logger : virtual logger {
private:
    std::string tag;
protected:
    std::string format(const std::string &message) {
        return "[" + tag + "] " + message;
    }
public:
    explicit tagged_logger(std::string tag_)
        : tag(std::move(tag_)) {}
    void log(const std::string &message) override {
        logger::log(format(message));
    }
};

struct cerr_logger : virtual logger {
    using logger::logger;
    void log(const std::string &message) override {
        std::cerr << message << "\n";
    }
};

struct tagged_cerr_logger : cerr_logger, tagged_logger {
    using tagged_logger::tagged_logger;
    void log(const std::string &message) override {
        cerr_logger::log(format(message));
    }
};

struct file_logger : virtual logger {
private:
    std::ofstream out;
public:
    explicit file_logger(const std::string &filename) : out(filename) {
        assert(out);
    }
    void log(const std::string &message) override {
        out << message << "\n";
    }
};

struct tagged_file_logger : file_logger, tagged_logger {
    explicit tagged_file_logger(const std::string &filename, std::string tag_)
        : file_logger(filename)
        , tagged_logger(std::move(tag_)) {}
    void log(const std::string &message) override {
        file_logger::log(format(message));
    }
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
        logger l;  // TODO
        test_plain_cout(l);
    }
    {
        tagged_logger l("MYTAG");  // TODO
        test_tagged_cout(l);
    }
    {
        cerr_logger l;  // TODO
        test_plain_cerr(l);
    }
    {
        tagged_cerr_logger l("MYTAG");  // TODO
        test_tagged_cerr(l);
    }
    {
        file_logger l("03-logger-plain.out");  // TODO
        test_plain_file(l);
    }
    {
        tagged_file_logger l("03-logger-tagged.out", "MYTAG");  // TODO
        test_tagged_file(l);
    }
}
