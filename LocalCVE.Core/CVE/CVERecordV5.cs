using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Text;

namespace LocalCVE.Core.CVE
{
    public static class V5
    {
        /* Links:
         * - Schema:                    https://github.com/CVEProject/cve-schema/blob/main/schema/CVE_Record_Format.json
         * - TypeScript Implementation: https://github.com/CVEProject/cve-core/blob/dev/src/cve/record/generated/CveRecordV5.ts
         * - Example:                   https://github.com/cveproject/cve-schema/blob/main/schema/docs/full-record-advanced-example.json
         * 
         * This is the C# adaptation of the TypeScript implementation (linked above).
         * */

        public class CVERecordV5
        {
            [JsonProperty("containers")]
            public Containers? Containers;

            [JsonProperty("cveMetadata")]
            public CVEMetadata? CVEMetadata;

            [JsonProperty("dataType")]
            public string? DataType;

            [JsonProperty("dataVersion")]
            public string? DataVersion;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class Containers
        {
            [JsonProperty("cna")]
            public CNAContainer CNA;

            [JsonProperty("adp")]
            public ADPContainer[]? ADP;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class CNAContainer
        {
            [JsonProperty("affected")]
            public Affected[] Affected;

            [JsonProperty("configurations")]
            public JToken[]? Configurations;

            [JsonProperty("credits")]
            public JToken[]? Credits;

            [JsonProperty("dateAssigned")]
            public DateTime? DateAssigned;

            [JsonProperty("datePublic")]
            public DateTime? DatePublic;

            [JsonProperty("descriptions")]
            public CNADescription[] Descriptions;

            [JsonProperty("exploits")]
            public JToken[]? Exploits;

            [JsonProperty("impacts")]
            public JToken[]? Impacts;

            [JsonProperty("metrics")]
            public JToken[]? Metrics;

            [JsonProperty("problemTypes")]
            public ProblemType[]? ProblemTypes;

            [JsonProperty("providerMetadata")]
            public ProviderMetadata ProviderMetadata;

            [JsonProperty("references")]
            public Reference[] References;

            [JsonProperty("solutions")]
            public JToken[]? Solutions;

            [JsonProperty("source")]
            public string? Source;

            [JsonProperty("tags")]
            public JToken[]? Tags;

            [JsonProperty("taxonomyMappings")]
            public JToken[]? TaxonomyMappings;

            [JsonProperty("timeline")]
            public JToken[]? Timeline;

            [JsonProperty("title")]
            public string? Title;

            [JsonProperty("workarounds")]
            public JToken[]? Workarounds;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class ADPContainer
        {
            [JsonProperty("affected")]
            public Affected[]? Affected;

            [JsonProperty("configurations")]
            public JToken[]? Configurations;

            [JsonProperty("credits")]
            public JToken[]? Credits;

            [JsonProperty("dateAssigned")]
            public DateTime? DateAssigned;

            [JsonProperty("datePublic")]
            public DateTime? DatePublic;

            [JsonProperty("descriptions")]
            public CNADescription[]? Descriptions;

            [JsonProperty("exploits")]
            public JToken[]? Exploits;

            [JsonProperty("impacts")]
            public JToken[]? Impacts;

            [JsonProperty("metrics")]
            public JToken[]? Metrics;

            [JsonProperty("problemTypes")]
            public ProblemType[]? ProblemTypes;

            [JsonProperty("providerMetadata")]
            public ProviderMetadata ProviderMetadata;

            [JsonProperty("references")]
            public Reference[]? References;

            [JsonProperty("solutions")]
            public JToken[]? Solutions;

            [JsonProperty("source")]
            public string? Source;

            [JsonProperty("tags")]
            public JToken[]? Tags;

            [JsonProperty("taxonomyMappings")]
            public JToken[]? TaxonomyMappings;

            [JsonProperty("timeline")]
            public JToken[]? Timeline;

            [JsonProperty("title")]
            public string? Title;

            [JsonProperty("workarounds")]
            public JToken[]? Workarounds;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class Affected
        {
            [JsonProperty("product")]
            public string? Product;

            [JsonProperty("vendor")]
            public string? Vendor;

            [JsonProperty("versions")]
            public Version[]? Versions;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class Version
        {
            [JsonProperty("status")]
            public string? Status;

            [JsonProperty("version")]
            public string? Value;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class CNADescription
        {
            [JsonProperty("lang")]
            public string? Lang;

            [JsonProperty("value")]
            public string? Value;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class ProblemType
        {
            [JsonProperty("descriptions")]
            public ProblemTypeDescription[]? Descriptions;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class ProblemTypeDescription
        {
            [JsonProperty("description")]
            public string? Description;

            [JsonProperty("lang")]
            public string? Lang;

            [JsonProperty("type")]
            public string? Type;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class ProviderMetadata
        {
            [JsonProperty("dateUpdated")]
            public DateTime? DateUpdated;

            [JsonProperty("orgId")]
            public string? OrgID;

            [JsonProperty("shortName")]
            public string? ShortName;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class Reference
        {
            [JsonProperty("name")]
            public string? Name;

            [JsonProperty("tags")]
            public string[]? Tags;

            [JsonProperty("url")]
            public string? URL;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }

        public class CVEMetadata
        {
            [JsonProperty("assignerOrgId")]
            public string? AssignerOrgID;

            [JsonProperty("assignerShortName")]
            public string? AssignerShortName;

            [JsonProperty("cveId")]
            public string? CVEID;

            [JsonProperty("datePublished")]
            public string? DatePublished;

            [JsonProperty("dateReserved")]
            public string? DateReserved;

            [JsonProperty("requesterUserId")]
            public string? RequesterUserID;

            [JsonProperty("state")]
            public string? State;

            [JsonExtensionData]
            public Dictionary<string, JToken>? Property;
        }
    }
}
