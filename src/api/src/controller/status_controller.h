#ifndef FID_API_STATUS_CONTROLLER
#define FID_API_STTAUS_CONTROLLER

#include "../status_service.h"

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/web/server/api/ApiController.hpp>

#include OATPP_CODEGEN_BEGIN(ApiController)

class StatusController : public oatpp::web::server::api::ApiController {

public:
  StatusController(const std::shared_ptr<ObjectMapper> &objectMapper)
      : oatpp::web::server::api::ApiController(objectMapper) {}

private:
  StatusService m_statusService;

public:
  static std::shared_ptr<StatusController>
  createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
    return std::make_shared<StatusController>(objectMapper);
  }

  // ENDPOINT("GET", "/", root) {
  //   const char *html = "<html lang='en'>"
  //                      "  <head>"
  //                      "    <meta charset=utf-8/>"
  //                      "  </head>"
  //                      "  <body>"
  //                      "    <p>Hello CRUD example project!</p>"
  //                      "    <a href='swagger/ui'>Checkout Swagger-UI
  //                      page</a>" "  </body>"
  //                      "</html>";

  //   auto response = createResponse(Status::CODE_200, html);
  //   response->putHeader(Header::CONTENT_TYPE, "text/html");
  //   return response;
  // }

  ENDPOINT_INFO(getStatus) {
    info->summary = "Get status";
    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
  }
  ENDPOINT("GET", "status", getStatus) {
    return createDtoResponse(Status::CODE_200, m_statusService.getStatus());
  }
};

#include OATPP_CODEGEN_BEGIN(ApiController)

#endif