//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef SFML_HTTP_HPP
#define SFML_HTTP_HPP

// Headers
#include <SFML/Network/Export.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <map>
#include <string>

namespace sf
{
    class SFML_NETWORK_API Http : NonCopyable {
        public:
            class SFML_NETWORK_API Request {
                public:
                    enum Method
                    {
                        Get,
                        Post,
                        Head
                    };

                    Request(const std::string &uri = "/", Method method = Get, const std::string &body = "");

                    void setField(const std::string &field, const std::string &value);

                    void setMethod(Method method);

                    void setUri(const std::string &uri);

                    void setHttpVersion(unsigned int major, unsigned int minor);

                    void setBody(const std::string &body);

                private:
                    friend class Http;

                    std::string prepare() const;

                    bool hasField(const std::string &field) const;

                    // Types
                    typedef std::map<std::string, std::string> FieldTable;

                    // Member data
                    FieldTable m_fields;
                    Method m_method;
                    std::string m_uri;
                    unsigned int m_majorVersion;
                    unsigned int m_minorVersion;
                    std::string m_body;
                };

            class SFML_NETWORK_API Response {
                public:
                    enum Status {
                        // 2xx: success
                        Ok = 200,
                        Created = 201,
                        Accepted = 202,
                        NoContent = 204,
                        ResetContent = 205,
                        PartialContent = 206,

                        // 3xx: redirection
                        MultipleChoices = 300,
                        MovedPermanently = 301,
                        MovedTemporarily = 302,
                        NotModified = 304,

                        // 4xx: client error
                        BadRequest = 400,
                        Unauthorized = 401,
                        Forbidden = 403,
                        NotFound = 404,
                        RangeNotSatisfiable = 407,

                        // 5xx: server error
                        InternalServerError = 500,
                        NotImplemented = 501,
                        BadGateway = 502,
                        ServiceNotAvailable = 503,
                        GatewayTimeout = 504,
                        VersionNotSupported = 505,

                        // 10xx: SFML custom codes
                        InvalidResponse = 1000,
                        ConnectionFailed = 1001
                    };

                    Response();

                    const std::string &getField(const std::string &field) const;

                    Status getStatus() const;

                    unsigned int getMajorHttpVersion() const;

                    unsigned int getMinorHttpVersion() const;

                    const std::string &getBody() const;

                private:
                    friend class Http;

                    void parse(const std::string &data);

                    // Types
                    typedef std::map<std::string, std::string> FieldTable;

                    // Member data
                    FieldTable m_fields;
                    Status m_status;
                    unsigned int m_majorVersion;
                    unsigned int m_minorVersion;
                    std::string m_body;
            };

            Http();

            Http(const std::string &host, unsigned short port = 0);

            void setHost(const std::string &host, unsigned short port = 0);

            Response sendRequest(const Request &request, Time timeout = Time::Zero);

        private:
            // Member data
            TcpSocket m_connection;
            IpAddress m_host;
            std::string m_hostName;
            unsigned short m_port;
    };

} // namespace sf

#endif // SFML_HTTP_HPP