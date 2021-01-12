#ifndef OATPP_TEST_API_ERROR_HANDLER
#define OATPP_TEST_API_ERROR_HANDLER

#include "dto/status_dto.h"

#include <oatpp/web/protocol/http/outgoing/ResponseFactory.hpp>
#include <oatpp/web/server/handler/ErrorHandler.hpp>

class ErrorHandler : public oatpp::web::server::handler::ErrorHandler {
private:
  typedef oatpp::web::protocol::http::outgoing::Response OutgoingResponse;
  typedef oatpp::web::protocol::http::Status Status;
  typedef oatpp::web::protocol::http::outgoing::ResponseFactory ResponseFactory;

private:
  std::shared_ptr<oatpp::data::mapping::ObjectMapper> objectMapper;

public:
  ErrorHandler(
      const std::shared_ptr<oatpp::data::mapping::ObjectMapper> &objectMapper);

  std::shared_ptr<OutgoingResponse>
  handleError(const Status &status, const oatpp::String &message,
              const Headers &headers) override;
};

#endif