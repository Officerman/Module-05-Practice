#include <iostream>
#include <memory>
#include <string>


class Document {
public:
    virtual void Open() = 0;  // Чисто виртуальный метод
    virtual ~Document() {}


class Report : public Document {
public:
    void Open() override {
        std::cout << "Opening Report document." << std::endl;
    }
};


class Resume : public Document {
public:
    void Open() override {
        std::cout << "Opening Resume document." << std::endl;
    }
};


class Letter : public Document {
public:
    void Open() override {
        std::cout << "Opening Letter document." << std::endl;
    }
};


class Invoice : public Document {
public:
    void Open() override {
        std::cout << "Opening Invoice document." << std::endl;
    }
};


class DocumentCreator {
public:
    virtual std::unique_ptr<Document> CreateDocument() = 0;  // Фабричный метод
    virtual ~DocumentCreator() {}
};


class ReportCreator : public DocumentCreator {
public:
    std::unique_ptr<Document> CreateDocument() override {
        return std::make_unique<Report>();
    }
};


class ResumeCreator : public DocumentCreator {
public:
    std::unique_ptr<Document> CreateDocument() override {
        return std::make_unique<Resume>();
    }
};


class LetterCreator : public DocumentCreator {
public:
    std::unique_ptr<Document> CreateDocument() override {
        return std::make_unique<Letter>();
    }
};


class InvoiceCreator : public DocumentCreator {
public:
    std::unique_ptr<Document> CreateDocument() override {
        return std::make_unique<Invoice>();
    }
};


void TestDocumentFactory(const std::string& documentType) {
    std::unique_ptr<DocumentCreator> creator;

    if (documentType == "Report") {
        creator = std::make_unique<ReportCreator>();
    } else if (documentType == "Resume") {
        creator = std::make_unique<ResumeCreator>();
    } else if (documentType == "Letter") {
        creator = std::make_unique<LetterCreator>();
    } else if (documentType == "Invoice") {
        creator = std::make_unique<InvoiceCreator>();
    } else {
        std::cout << "Unknown document type!" << std::endl;
        return;
    }

    std::unique_ptr<Document> document = creator->CreateDocument();
    document->Open();
}

int main() {
    TestDocumentFactory("Report");
    TestDocumentFactory("Resume");
    TestDocumentFactory("Letter");
    TestDocumentFactory("Invoice");

    std::string userInput;
    std::cout << "Enter document type (Report, Resume, Letter, Invoice): ";
    std::cin >> userInput;
    TestDocumentFactory(userInput);

    return 0;
}
