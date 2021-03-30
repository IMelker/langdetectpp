#include <langdetectpp/language.h>

namespace langdetectpp
{

std::string toShortName(Language lang)
{
    switch (lang)
    {
    case Language::AF:
        return "AF";
    case Language::AR:
        return "AR";
    case Language::BG:
        return "BG";
    case Language::BN:
        return "BN";
    case Language::CA:
        return "CA";
    case Language::CS:
        return "CS";
    case Language::CY:
        return "CY";
    case Language::DA:
        return "DA";
    case Language::DE:
        return "DE";
    case Language::EL:
        return "EL";
    case Language::EN:
        return "EN";
    case Language::ES:
        return "ES";
    case Language::ET:
        return "ET";
    case Language::FA:
        return "FA";
    case Language::FI:
        return "FI";
    case Language::FR:
        return "FR";
    case Language::GU:
        return "GU";
    case Language::HE:
        return "HE";
    case Language::HI:
        return "HI";
    case Language::HR:
        return "HR";
    case Language::HU:
        return "HU";
    case Language::ID:
        return "ID";
    case Language::IT:
        return "IT";
    case Language::JA:
        return "JA";
    case Language::KN:
        return "KN";
    case Language::KO:
        return "KO";
    case Language::LT:
        return "LT";
    case Language::LV:
        return "LV";
    case Language::MK:
        return "MK";
    case Language::ML:
        return "ML";
    case Language::MR:
        return "MR";
    case Language::NE:
        return "NE";
    case Language::NL:
        return "NL";
    case Language::NO:
        return "NO";
    case Language::PA:
        return "PA";
    case Language::PL:
        return "PL";
    case Language::PT:
        return "PT";
    case Language::RO:
        return "RO";
    case Language::RU:
        return "RU";
    case Language::SK:
        return "SK";
    case Language::SL:
        return "SL";
    case Language::SO:
        return "SO";
    case Language::SQ:
        return "SQ";
    case Language::SV:
        return "SV";
    case Language::SW:
        return "SW";
    case Language::TA:
        return "TA";
    case Language::TE:
        return "TE";
    case Language::TH:
        return "TH";
    case Language::TL:
        return "TL";
    case Language::TR:
        return "TR";
    case Language::UK:
        return "UK";
    case Language::UR:
        return "UR";
    case Language::VI:
        return "VI";
    case Language::ZH_CN:
        return "ZH_CN";
    case Language::ZH_TW:
        return "ZH_TW";
    case Language::UNKNOWN:
      return "UNKNOWN";
    default:
        return "NOT_RECOGNIZED";
    }
}

Language fromShortName(const std::string& lang)
{
  if (lang == "AF")
    return Language::AF;
  if (lang == "AR")
    return Language::AR;
  if (lang == "BG")
    return Language::BG;
  if (lang == "BN")
    return Language::BN;
  if (lang == "CA")
    return Language::CA;
  if (lang == "CS")
    return Language::CS;
  if (lang == "CY")
    return Language::CY;
  if (lang == "DA")
    return Language::DA;
  if (lang == "DE")
    return Language::DE;
  if (lang == "EL")
    return Language::EL;
  if (lang == "EN")
    return Language::EN;
  if (lang == "ES")
    return Language::ES;
  if (lang == "ET")
    return Language::ET;
  if (lang == "FA")
    return Language::FA;
  if (lang == "FI")
    return Language::FI;
  if (lang == "FR")
    return Language::FR;
  if (lang == "GU")
    return Language::GU;
  if (lang == "HE")
    return Language::HE;
  if (lang == "HI")
    return Language::HI;
  if (lang == "HR")
    return Language::HR;
  if (lang == "HU")
    return Language::HU;
  if (lang == "ID")
    return Language::ID;
  if (lang == "IT")
    return Language::IT;
  if (lang == "JA")
    return Language::JA;
  if (lang == "KN")
    return Language::KN;
  if (lang == "KO")
    return Language::KO;
  if (lang == "LT")
    return Language::LT;
  if (lang == "LV")
    return Language::LV;
  if (lang == "MK")
    return Language::MK;
  if (lang == "ML")
    return Language::ML;
  if (lang == "MR")
    return Language::MR;
  if (lang == "NE")
    return Language::NE;
  if (lang == "NL")
    return Language::NL;
  if (lang == "NO")
    return Language::NO;
  if (lang == "PA")
    return Language::PA;
  if (lang == "PL")
    return Language::PL;
  if (lang == "PT")
    return Language::PT;
  if (lang == "RO")
    return Language::RO;
  if (lang == "RU")
    return Language::RU;
  if (lang == "SK")
    return Language::SK;
  if (lang == "SL")
    return Language::SL;
  if (lang == "SO")
    return Language::SO;
  if (lang == "SQ")
    return Language::SQ;
  if (lang == "SV")
    return Language::SV;
  if (lang == "SW")
    return Language::SW;
  if (lang == "TA")
    return Language::TA;
  if (lang == "TE")
    return Language::TE;
  if (lang == "TH")
    return Language::TH;
  if (lang == "TL")
    return Language::TL;
  if (lang == "TR")
    return Language::TR;
  if (lang == "UK")
    return Language::UK;
  if (lang == "UR")
    return Language::UR;
  if (lang == "VI")
    return Language::VI;
  if (lang == "ZH_CN")
    return Language::ZH_CN;
  if (lang == "ZH_TW")
    return Language::ZH_TW;
  return Language::UNKNOWN;
}

std::string toLongName(Language lang)
{
    switch (lang)
    {
    case Language::AF:
      return "Afrikaans";
    case Language::AR:
      return "Arabic";
    case Language::BG:
      return "Bulgarian";
    case Language::BN:
      return "Bengali";
    case Language::CA:
      return "Catalan";
    case Language::CS:
      return "Czech";
    case Language::CY:
      return "Welsh";
    case Language::DA:
      return "Danish";
    case Language::DE:
      return "German";
    case Language::EL:
      return "Greek";
    case Language::EN:
      return "English";
    case Language::ES:
      return "Spanish";
    case Language::ET:
      return "Estonian";
    case Language::FA:
      return "Persian";
    case Language::FI:
      return "Finnish";
    case Language::FR:
      return "French";
    case Language::GU:
      return "Gujarati";
    case Language::HE:
      return "Hebrew";
    case Language::HI:
      return "Hindi";
    case Language::HR:
      return "Croatian";
    case Language::HU:
      return "Hungarian";
    case Language::ID:
      return "Indonesian";
    case Language::IT:
      return "Italian";
    case Language::JA:
      return "Japanese";
    case Language::KN:
      return "Kannada";
    case Language::KO:
      return "Korean";
    case Language::LT:
      return "Lithuanian";
    case Language::LV:
      return "Latvian";
    case Language::MK:
      return "Macedonian";
    case Language::ML:
      return "Malayalam";
    case Language::MR:
      return "Marathi";
    case Language::NE:
      return "Nepali";
    case Language::NL:
      return "Dutch";
    case Language::NO:
      return "Norwegian";
    case Language::PA:
      return "Panjabi";
    case Language::PL:
      return "Polish";
    case Language::PT:
      return "Portuguese";
    case Language::RO:
      return "Romanian";
    case Language::RU:
      return "Russian";
    case Language::SK:
      return "Slovak";
    case Language::SL:
      return "Slovenian";
    case Language::SO:
      return "Somali";
    case Language::SQ:
      return "Albanian";
    case Language::SV:
      return "Swedish";
    case Language::SW:
      return "Swahili";
    case Language::TA:
      return "Tamil";
    case Language::TE:
      return "Telugu";
    case Language::TH:
      return "Thai";
    case Language::TL:
      return "Tagalog";
    case Language::TR:
      return "Turkish";
    case Language::UK:
      return "Ukrainian";
    case Language::UR:
      return "Urdu";
    case Language::VI:
      return "Vietnamese";
    case Language::ZH_CN:
      return "Simplified Chinese";
    case Language::ZH_TW:
      return "Traditional Chinese";
    case Language::UNKNOWN:
      return "UNKNOWN";
    default:
      return "NOT_RECOGNIZED";
    }
}

Language fromLongName(const std::string& lang)
{
  if (lang == "Afrikaans")
    return Language::AF;
  if (lang == "Arabic")
    return Language::AR;
  if (lang == "Bulgarian")
    return Language::BG;
  if (lang == "Bengali")
    return Language::BN;
  if (lang == "Catalan")
    return Language::CA;
  if (lang == "Czech")
    return Language::CS;
  if (lang == "Welsh")
    return Language::CY;
  if (lang == "Danish")
    return Language::DA;
  if (lang == "German")
    return Language::DE;
  if (lang == "Greek")
    return Language::EL;
  if (lang == "English")
    return Language::EN;
  if (lang == "Spanish")
    return Language::ES;
  if (lang == "Estonian")
    return Language::ET;
  if (lang == "Persian")
    return Language::FA;
  if (lang == "Finnish")
    return Language::FI;
  if (lang == "French")
    return Language::FR;
  if (lang == "Gujarati")
    return Language::GU;
  if (lang == "Hebrew")
    return Language::HE;
  if (lang == "Hindi")
    return Language::HI;
  if (lang == "Croatian")
    return Language::HR;
  if (lang == "Hungarian")
    return Language::HU;
  if (lang == "Indonesian")
    return Language::ID;
  if (lang == "Italian")
    return Language::IT;
  if (lang == "Japanese")
    return Language::JA;
  if (lang == "Kannada")
    return Language::KN;
  if (lang == "Korean")
    return Language::KO;
  if (lang == "Lithuanian")
    return Language::LT;
  if (lang == "Latvian")
    return Language::LV;
  if (lang == "Macedonian")
    return Language::MK;
  if (lang == "Malayalam")
    return Language::ML;
  if (lang == "Marathi")
    return Language::MR;
  if (lang == "Nepali")
    return Language::NE;
  if (lang == "Dutch")
    return Language::NL;
  if (lang == "Norwegian")
    return Language::NO;
  if (lang == "Panjabi")
    return Language::PA;
  if (lang == "Polish")
    return Language::PL;
  if (lang == "Portuguese")
    return Language::PT;
  if (lang == "Romanian")
    return Language::RO;
  if (lang == "Russian")
    return Language::RU;
  if (lang == "Slovak")
    return Language::SK;
  if (lang == "Slovenian")
    return Language::SL;
  if (lang == "Somali")
    return Language::SO;
  if (lang == "Albanian")
    return Language::SQ;
  if (lang == "Swedish")
    return Language::SV;
  if (lang == "Swahili")
    return Language::SW;
  if (lang == "Tamil")
    return Language::TA;
  if (lang == "Telugu")
    return Language::TE;
  if (lang == "Thai")
    return Language::TH;
  if (lang == "Tagalog")
    return Language::TL;
  if (lang == "Turkish")
    return Language::TR;
  if (lang == "Ukrainian")
    return Language::UK;
  if (lang == "Urdu")
    return Language::UR;
  if (lang == "Vietnamese")
    return Language::VI;
  if (lang == "Simplified Chinese")
    return Language::ZH_CN;
  if (lang == "Traditional Chinese")
    return Language::ZH_TW;
  return Language::UNKNOWN;
}

}  // namespace langdetectpp
