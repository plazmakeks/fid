#include "error_handler.h"

ErrorHandler::ErrorHandler(
    const std::shared_ptr<oatpp::data::mapping::ObjectMapper> &objectMapper)
    : objectMapper(objectMapper) {}

std::shared_ptr<ErrorHandler::OutgoingResponse>
ErrorHandler::handleError(const Status &status, const oatpp::String &message,
                          const Headers &headers) {
  auto error = StatusDto::createShared();
  error->status = State(1);

  auto response = ResponseFactory::createResponse(status, error, objectMapper);
  for (const auto &pair : headers.getAll()) {
    response->putHeader(pair.first.toString(), pair.second.toString());
  }

  return response;
}