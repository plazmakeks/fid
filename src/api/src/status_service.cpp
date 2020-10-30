#include "status_service.h"

oatpp::Object<StatusDto> StatusService::getStatus() {
  auto obj = StatusDto::createShared();
  obj->status = State(0);
  return obj;
}