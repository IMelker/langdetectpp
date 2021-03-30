## langdetectpp

C++ port of the Java [language-detection](https://github.com/shuyo/language-detection) library.

It analyzes UTF8-encoded text and returns the most likely human language of the contents.

It uses the same language profiles as the original library, which are based on 1-3 character N-grams.  These profiles cover 55 different languages.

```c++
#include <string>
#include <iostream>
#include <langdetectpp/langdetectpp.h>

using langdetectpp::Detector;
using langdetectpp::Language;

int main() {
    auto detector = Detector::create();
    std::string someEnglishText = "Some english text to analyze.";
    Language lang = detector->detect(someEnglishText);
    std::cout << langdetectpp::toShortName(lang) << std::endl;

    std::string someGermanText = "Im Rahmen der Trainingskontrollen k\u00f6nnen etwa 8.650 Kaderathleten gepr\u00fcft werden, die in drei Testpools aufgeteilt sind und an nationalen und internationalen Wettk\u00e4mpfen teilnehmen.";
    lang = detector->detect(someGermanText);
    std::cout << langdetectpp::toShortName(lang) << std::endl;
}
```

```bash
EN
DE
```

### building

```bash
mkdir build
cd build
cmake ../
make
```

### usage
The main public-facing part of this library is the `Detector` class.  This class is instantiated through the `Detector::create()` static method, which returns a `shared_ptr`.
Initializing a `Detector` is relatively expensive because it needs to build up the initial ngram vs language score matrix.  Because of this, a `Detector` instance should be kept around and reused.

`Detector` is thread-safe and has no mutable state.  You should only need a single instance for anything.

The most likely language for a given string is returned as a `langdetect::Language`, which is an enum class.  There is a utility method for getting the string of the corresponding language code:

```c++
    std::string toShortName(langdetectpp::Language);
```

```c++
    auto lang = langdetectpp::Language::EN;
    string langName = langdetectpp::toShortName(lang);
```

There is also a utility method for getting the English name of the language code:

```c++
    std::string toLongName(langdetectpp::Language)
```

```c++
    auto lang = langdetectpp::Language::AR;
    string langName = langdetectpp::toLongName(lang);
    std::cout << langName << std::endl;
    // "Arabic"
```

### roadmap
- TODO Set priority information about language probabilities
- TODO Detect languages with multiple probabilities

### license

Apache License version 2.0 (commercial-friendly) -- see the `LICENSE` file for the formal version.

Language profiles are taken from [the original Java language-detection project](https://github.com/shuyo/language-detection/blob/wiki/ProjectHome.md).  These profiles are (c) 2010-2014 Cybozu Labs, Inc., and are likewise licensed under Apache 2.0 (and are also commercial-friendly).  The `LICENSE` file contains the text of the original license for the profiles.
