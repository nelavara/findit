#pragma once

class BadFile {
    public:
        BadFile() = default;
        ~BadFile() = default;
        ostream& print(ostream& out) {
            out << "File Path was invalid or did not exist.\n";
            return out;
        }
};

inline ostream& operator << (ostream& out, BadFile& bf) { return bf.print(out); }