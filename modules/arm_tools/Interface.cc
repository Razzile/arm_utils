#include <node.h>
#include <v8.h>
#include <string>
#include "ARMDisassembler.h"

const char* ToCString(const v8::String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

void ARM_Init(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  v8::HandleScope scope(isolate);
  ARMDisassembler ds;

  v8::String::Utf8Value local(args[0]->ToString());
  std::string str = ToCString(local);
  std::string result = ds.Disassemble(0x0, std::stoul(str, nullptr, 16));

  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, result.data()));
}

void init(v8::Local<v8::Object> target) {
  NODE_SET_METHOD(target, "decodeARM", ARM_Init);
}

NODE_MODULE(ARM, init);
