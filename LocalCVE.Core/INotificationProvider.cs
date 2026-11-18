using System;
using System.Collections.Generic;
using System.Text;

namespace LocalCVE.Core
{
    public interface INotificationProvider
    {
        public static Dictionary<string, Type> NotificationProviders = new();
    }
}
