﻿<?xml version="1.0"?>
<!--
  有关如何配置 ASP.NET 应用程序的详细信息，请访问
  http://go.microsoft.com/fwlink/?LinkId=169433
  -->
<configuration>
  <system.web>
    <compilation debug="true" targetFramework="4.5"/>
    <httpRuntime targetFramework="4.5"/>
  </system.web>
  <system.webServer>
    <handlers>
      <add name="ProcessRequest" path="*" verb="*" type="${appName}Mock.MockHandler"/>
    </handlers>
  </system.webServer>
</configuration>