#ifndef API_SERVICE_STATUS_H
#define API_SERVICE_STATUS_H


#include "dto/status_dto.h"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class StatusService {
    private:
        typedef oatpp::web::protocol::http::Status status;
    public:
        oatpp::Object<StatusDto> getStatus();
};

#endif