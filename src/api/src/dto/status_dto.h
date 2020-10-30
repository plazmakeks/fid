#ifndef API_DTO_STATUS_H
#define API_DTO_STATUS_H

#include <oatpp/core/Types.hpp>
#include <oatpp/core/macro/codegen.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

ENUM(State, v_int32, VALUE(ONLINE, 0, "online"), VALUE(OFFLINE, 1, "offline"))

class StatusDto : public oatpp::DTO {
  DTO_INIT(StatusDto, DTO)

  DTO_FIELD_INFO(status) { info->description = "status of rest api"; }
  DTO_FIELD(Enum<State>::AsString, status, "status");
};

#include OATPP_CODEGEN_END(DTO)

#endif