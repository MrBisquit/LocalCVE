using System;
using System.Collections.Generic;
using System.Text;

namespace LocalCVE.Core.LCVE
{
    /* My own record type, based on OSV.
     * This is designed to be a data type that can easily tie everything
     * together, from the database, CVE, and OSV.
     * 
     * All data should be converted to this format.
     * */
    public class LCVERecord
    {
        public string ID;

        public DateTime Published;
        public DateTime Modified;
        public DateTime? Withdrawn;
    }
}
