#include <node.h>
#include <v8.h>
#include <string>
#include "ARMDisassembler.h"

void ARM_Init(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  v8::HandleScope scope(isolate);
  ARMDisassembler ds;

  unsigned int hex = args[0]->NumberValue();
  std::string result = ds.Disassemble(0x0, hex);

  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, result.data()));
}

void init(v8::Local<v8::Object> target) {
  NODE_SET_METHOD(target, "decodeARM", ARM_Init);
}

NODE_MODULE(ARM, init);
