using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Text;

namespace LocalCVE.Core.OSV
{
    public class OSVRecord
    {
        /* Links:
         * - Schema:  https://ossf.github.io/osv-schema/
         * - Example: https://api.osv.dev/v1/vulns/GHSA-p2x3-8689-cwpg
         * - Proto:   https://github.com/ossf/osv-schema/blob/main/proto/vulnerability.proto
         * 
         * This might be wrong.
         * */

        public class Record
        {
            [JsonProperty("schema_version")]
            public string SchemaVersion;

            [JsonProperty("id")]
            public string ID;

            [JsonProperty("published")]
            public string Published;

            [JsonProperty("modified")]
            public string Modified;

            [JsonProperty("withdrawn")]
            public string? Withdrawn;

            [JsonProperty("aliases")]
            public string[]? Aliases;

            [JsonProperty("related")]
            public string[]? Related;

            [JsonProperty("upstream")]
            public string[]? Upstream;

            [JsonProperty("summary")]
            public string Summary;

            [JsonProperty("details")]
            public string Details;

            [JsonProperty("affected")]
            public Affected[] Affected;

            [JsonProperty("references")]
            public Reference[]? References;

            [JsonProperty("database_specific")]
            public JObject? DatabaseSpecific;

            [JsonProperty("severity")]
            public Severity[]? Severity;

            [JsonProperty("credits")]
            public Credit[]? Credits;
        }

        public class Commit
        {
            // Deprecated

            [JsonProperty("repo_type")]
            public string RepoType;

            [JsonProperty("repo_url")]
            public string RepoURL;

            [JsonProperty("commit")]
            public string Commit;
        }

        public class Package
        {
            [JsonProperty("name")]
            public string Name;

            [JsonProperty("ecosystem")]
            public string Ecosystem;

            [JsonProperty("purl")]
            public string? Purl;
        }

        public class Event
        {
            [JsonProperty("introduced")]
            public string Introduced;

            [JsonProperty("fixed")]
            public string Fixed;

            [JsonProperty("limit")]
            public string Limit;

            [JsonProperty("last_affected")]
            public string LastAffected;
        }

        public class Range
        {
            [JsonProperty("type")]
            public string Type;

            [JsonProperty("repo")]
            public string? Repo;

            [JsonProperty("events")]
            public Event[] Events;

            [JsonProperty("database_specific")]
            public JObject? DatabaseSpecific;
        }

        public class Affected
        {
            [JsonProperty("package")]
            public Package? Package;

            [JsonProperty("ranges")]
            public Range[] Ranges;

            [JsonProperty("versions")]
            public string[]? Versions;

            [JsonProperty("ecosystem_specific")]
            public JObject? EcosystemSpecific;

            [JsonProperty("database_specific")]
            public JObject? DatabaseSpecific;

            [JsonProperty("severity")]
            public Severity[]? Severity;
        }

        public class Severity
        {
            [JsonProperty("type")]
            public string Type;

            [JsonProperty("score")]
            public string Score;

            [JsonProperty("source")]
            public string Source;
        }

        public class Credit
        {
            [JsonProperty("name")]
            public string Name;

            [JsonProperty("contact")]
            public string[] Contact;

            [JsonProperty("type")]
            public string Type;
        }

        public class Reference
        {
            [JsonProperty("type")]
            public string Type;

            [JsonProperty("url")]
            public string URL;
        }
    }
}
