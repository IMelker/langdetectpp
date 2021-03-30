#pragma once

#include <string>

namespace langdetectpp
{

enum class Language
{
    AF,
    AR,
    BG,
    BN,
    CA,
    CS,
    CY,
    DA,
    DE,
    EL,
    EN,
    ES,
    ET,
    FA,
    FI,
    FR,
    GU,
    HE,
    HI,
    HR,
    HU,
    ID,
    IT,
    JA,
    KN,
    KO,
    LT,
    LV,
    MK,
    ML,
    MR,
    NE,
    NL,
    NO,
    PA,
    PL,
    PT,
    RO,
    RU,
    SK,
    SL,
    SO,
    SQ,
    SV,
    SW,
    TA,
    TE,
    TH,
    TL,
    TR,
    UK,
    UNKNOWN,
    UR,
    VI,
    ZH_CN,
    ZH_TW,
};

// ISO 639-1 codes
std::string toShortName(Language lang);
Language fromShortName(const std::string& lang);

// ISO language name
std::string toLongName(Language lang);
Language fromLongName(const std::string& lang);




} // langdetectpp
