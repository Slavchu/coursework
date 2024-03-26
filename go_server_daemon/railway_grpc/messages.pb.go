// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.30.0
// 	protoc        v4.25.3
// source: messages.proto

package railway_grpc

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type ETrainState int32

const (
	ETrainState_IN_TRIP    ETrainState = 0
	ETrainState_IN_QUEUE   ETrainState = 1
	ETrainState_ARRIVED    ETrainState = 2
	ETrainState_DEPARTURED ETrainState = 3
)

// Enum value maps for ETrainState.
var (
	ETrainState_name = map[int32]string{
		0: "IN_TRIP",
		1: "IN_QUEUE",
		2: "ARRIVED",
		3: "DEPARTURED",
	}
	ETrainState_value = map[string]int32{
		"IN_TRIP":    0,
		"IN_QUEUE":   1,
		"ARRIVED":    2,
		"DEPARTURED": 3,
	}
)

func (x ETrainState) Enum() *ETrainState {
	p := new(ETrainState)
	*p = x
	return p
}

func (x ETrainState) String() string {
	return protoimpl.X.EnumStringOf(x.Descriptor(), protoreflect.EnumNumber(x))
}

func (ETrainState) Descriptor() protoreflect.EnumDescriptor {
	return file_messages_proto_enumTypes[0].Descriptor()
}

func (ETrainState) Type() protoreflect.EnumType {
	return &file_messages_proto_enumTypes[0]
}

func (x ETrainState) Number() protoreflect.EnumNumber {
	return protoreflect.EnumNumber(x)
}

// Deprecated: Use ETrainState.Descriptor instead.
func (ETrainState) EnumDescriptor() ([]byte, []int) {
	return file_messages_proto_rawDescGZIP(), []int{0}
}

type VirtualTrainTemplate struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Num             uint32 `protobuf:"varint,1,opt,name=num,proto3" json:"num,omitempty"`
	TimeIntervalMin uint32 `protobuf:"varint,2,opt,name=time_interval_min,json=timeIntervalMin,proto3" json:"time_interval_min,omitempty"`
	TimeIntervalMax uint32 `protobuf:"varint,3,opt,name=time_interval_max,json=timeIntervalMax,proto3" json:"time_interval_max,omitempty"`
	TimeToStay      uint32 `protobuf:"varint,4,opt,name=time_to_stay,json=timeToStay,proto3" json:"time_to_stay,omitempty"`
}

func (x *VirtualTrainTemplate) Reset() {
	*x = VirtualTrainTemplate{}
	if protoimpl.UnsafeEnabled {
		mi := &file_messages_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *VirtualTrainTemplate) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*VirtualTrainTemplate) ProtoMessage() {}

func (x *VirtualTrainTemplate) ProtoReflect() protoreflect.Message {
	mi := &file_messages_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use VirtualTrainTemplate.ProtoReflect.Descriptor instead.
func (*VirtualTrainTemplate) Descriptor() ([]byte, []int) {
	return file_messages_proto_rawDescGZIP(), []int{0}
}

func (x *VirtualTrainTemplate) GetNum() uint32 {
	if x != nil {
		return x.Num
	}
	return 0
}

func (x *VirtualTrainTemplate) GetTimeIntervalMin() uint32 {
	if x != nil {
		return x.TimeIntervalMin
	}
	return 0
}

func (x *VirtualTrainTemplate) GetTimeIntervalMax() uint32 {
	if x != nil {
		return x.TimeIntervalMax
	}
	return 0
}

func (x *VirtualTrainTemplate) GetTimeToStay() uint32 {
	if x != nil {
		return x.TimeToStay
	}
	return 0
}

type TrainArray struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	TrainArray []*Train `protobuf:"bytes,1,rep,name=train_array,json=trainArray,proto3" json:"train_array,omitempty"`
}

func (x *TrainArray) Reset() {
	*x = TrainArray{}
	if protoimpl.UnsafeEnabled {
		mi := &file_messages_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *TrainArray) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*TrainArray) ProtoMessage() {}

func (x *TrainArray) ProtoReflect() protoreflect.Message {
	mi := &file_messages_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use TrainArray.ProtoReflect.Descriptor instead.
func (*TrainArray) Descriptor() ([]byte, []int) {
	return file_messages_proto_rawDescGZIP(), []int{1}
}

func (x *TrainArray) GetTrainArray() []*Train {
	if x != nil {
		return x.TrainArray
	}
	return nil
}

type Train struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Id         uint32      `protobuf:"varint,1,opt,name=id,proto3" json:"id,omitempty"`
	Name       string      `protobuf:"bytes,2,opt,name=name,proto3" json:"name,omitempty"`
	Wagons     uint32      `protobuf:"varint,3,opt,name=wagons,proto3" json:"wagons,omitempty"`
	TrainState ETrainState `protobuf:"varint,4,opt,name=train_state,json=trainState,proto3,enum=GRPCRailway.ETrainState" json:"train_state,omitempty"`
}

func (x *Train) Reset() {
	*x = Train{}
	if protoimpl.UnsafeEnabled {
		mi := &file_messages_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *Train) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Train) ProtoMessage() {}

func (x *Train) ProtoReflect() protoreflect.Message {
	mi := &file_messages_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Train.ProtoReflect.Descriptor instead.
func (*Train) Descriptor() ([]byte, []int) {
	return file_messages_proto_rawDescGZIP(), []int{2}
}

func (x *Train) GetId() uint32 {
	if x != nil {
		return x.Id
	}
	return 0
}

func (x *Train) GetName() string {
	if x != nil {
		return x.Name
	}
	return ""
}

func (x *Train) GetWagons() uint32 {
	if x != nil {
		return x.Wagons
	}
	return 0
}

func (x *Train) GetTrainState() ETrainState {
	if x != nil {
		return x.TrainState
	}
	return ETrainState_IN_TRIP
}

type RailwayState struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	RailNum uint32   `protobuf:"varint,1,opt,name=rail_num,json=railNum,proto3" json:"rail_num,omitempty"`
	Trains  []*Train `protobuf:"bytes,2,rep,name=trains,proto3" json:"trains,omitempty"`
}

func (x *RailwayState) Reset() {
	*x = RailwayState{}
	if protoimpl.UnsafeEnabled {
		mi := &file_messages_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *RailwayState) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*RailwayState) ProtoMessage() {}

func (x *RailwayState) ProtoReflect() protoreflect.Message {
	mi := &file_messages_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use RailwayState.ProtoReflect.Descriptor instead.
func (*RailwayState) Descriptor() ([]byte, []int) {
	return file_messages_proto_rawDescGZIP(), []int{3}
}

func (x *RailwayState) GetRailNum() uint32 {
	if x != nil {
		return x.RailNum
	}
	return 0
}

func (x *RailwayState) GetTrains() []*Train {
	if x != nil {
		return x.Trains
	}
	return nil
}

type Empty struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *Empty) Reset() {
	*x = Empty{}
	if protoimpl.UnsafeEnabled {
		mi := &file_messages_proto_msgTypes[4]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *Empty) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Empty) ProtoMessage() {}

func (x *Empty) ProtoReflect() protoreflect.Message {
	mi := &file_messages_proto_msgTypes[4]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Empty.ProtoReflect.Descriptor instead.
func (*Empty) Descriptor() ([]byte, []int) {
	return file_messages_proto_rawDescGZIP(), []int{4}
}

var File_messages_proto protoreflect.FileDescriptor

var file_messages_proto_rawDesc = []byte{
	0x0a, 0x0e, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x73, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x12, 0x0b, 0x47, 0x52, 0x50, 0x43, 0x52, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x22, 0xa2, 0x01,
	0x0a, 0x14, 0x56, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6c, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x54, 0x65,
	0x6d, 0x70, 0x6c, 0x61, 0x74, 0x65, 0x12, 0x10, 0x0a, 0x03, 0x6e, 0x75, 0x6d, 0x18, 0x01, 0x20,
	0x01, 0x28, 0x0d, 0x52, 0x03, 0x6e, 0x75, 0x6d, 0x12, 0x2a, 0x0a, 0x11, 0x74, 0x69, 0x6d, 0x65,
	0x5f, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x5f, 0x6d, 0x69, 0x6e, 0x18, 0x02, 0x20,
	0x01, 0x28, 0x0d, 0x52, 0x0f, 0x74, 0x69, 0x6d, 0x65, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61,
	0x6c, 0x4d, 0x69, 0x6e, 0x12, 0x2a, 0x0a, 0x11, 0x74, 0x69, 0x6d, 0x65, 0x5f, 0x69, 0x6e, 0x74,
	0x65, 0x72, 0x76, 0x61, 0x6c, 0x5f, 0x6d, 0x61, 0x78, 0x18, 0x03, 0x20, 0x01, 0x28, 0x0d, 0x52,
	0x0f, 0x74, 0x69, 0x6d, 0x65, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x4d, 0x61, 0x78,
	0x12, 0x20, 0x0a, 0x0c, 0x74, 0x69, 0x6d, 0x65, 0x5f, 0x74, 0x6f, 0x5f, 0x73, 0x74, 0x61, 0x79,
	0x18, 0x04, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0a, 0x74, 0x69, 0x6d, 0x65, 0x54, 0x6f, 0x53, 0x74,
	0x61, 0x79, 0x22, 0x41, 0x0a, 0x0a, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x41, 0x72, 0x72, 0x61, 0x79,
	0x12, 0x33, 0x0a, 0x0b, 0x74, 0x72, 0x61, 0x69, 0x6e, 0x5f, 0x61, 0x72, 0x72, 0x61, 0x79, 0x18,
	0x01, 0x20, 0x03, 0x28, 0x0b, 0x32, 0x12, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52, 0x61, 0x69, 0x6c,
	0x77, 0x61, 0x79, 0x2e, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x52, 0x0a, 0x74, 0x72, 0x61, 0x69, 0x6e,
	0x41, 0x72, 0x72, 0x61, 0x79, 0x22, 0x7e, 0x0a, 0x05, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x12, 0x0e,
	0x0a, 0x02, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x02, 0x69, 0x64, 0x12, 0x12,
	0x0a, 0x04, 0x6e, 0x61, 0x6d, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x09, 0x52, 0x04, 0x6e, 0x61,
	0x6d, 0x65, 0x12, 0x16, 0x0a, 0x06, 0x77, 0x61, 0x67, 0x6f, 0x6e, 0x73, 0x18, 0x03, 0x20, 0x01,
	0x28, 0x0d, 0x52, 0x06, 0x77, 0x61, 0x67, 0x6f, 0x6e, 0x73, 0x12, 0x39, 0x0a, 0x0b, 0x74, 0x72,
	0x61, 0x69, 0x6e, 0x5f, 0x73, 0x74, 0x61, 0x74, 0x65, 0x18, 0x04, 0x20, 0x01, 0x28, 0x0e, 0x32,
	0x18, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x45, 0x54,
	0x72, 0x61, 0x69, 0x6e, 0x53, 0x74, 0x61, 0x74, 0x65, 0x52, 0x0a, 0x74, 0x72, 0x61, 0x69, 0x6e,
	0x53, 0x74, 0x61, 0x74, 0x65, 0x22, 0x55, 0x0a, 0x0c, 0x52, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79,
	0x53, 0x74, 0x61, 0x74, 0x65, 0x12, 0x19, 0x0a, 0x08, 0x72, 0x61, 0x69, 0x6c, 0x5f, 0x6e, 0x75,
	0x6d, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x07, 0x72, 0x61, 0x69, 0x6c, 0x4e, 0x75, 0x6d,
	0x12, 0x2a, 0x0a, 0x06, 0x74, 0x72, 0x61, 0x69, 0x6e, 0x73, 0x18, 0x02, 0x20, 0x03, 0x28, 0x0b,
	0x32, 0x12, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x54,
	0x72, 0x61, 0x69, 0x6e, 0x52, 0x06, 0x74, 0x72, 0x61, 0x69, 0x6e, 0x73, 0x22, 0x07, 0x0a, 0x05,
	0x45, 0x6d, 0x70, 0x74, 0x79, 0x2a, 0x45, 0x0a, 0x0b, 0x45, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x53,
	0x74, 0x61, 0x74, 0x65, 0x12, 0x0b, 0x0a, 0x07, 0x49, 0x4e, 0x5f, 0x54, 0x52, 0x49, 0x50, 0x10,
	0x00, 0x12, 0x0c, 0x0a, 0x08, 0x49, 0x4e, 0x5f, 0x51, 0x55, 0x45, 0x55, 0x45, 0x10, 0x01, 0x12,
	0x0b, 0x0a, 0x07, 0x41, 0x52, 0x52, 0x49, 0x56, 0x45, 0x44, 0x10, 0x02, 0x12, 0x0e, 0x0a, 0x0a,
	0x44, 0x45, 0x50, 0x41, 0x52, 0x54, 0x55, 0x52, 0x45, 0x44, 0x10, 0x03, 0x32, 0x91, 0x03, 0x0a,
	0x07, 0x52, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x12, 0x42, 0x0a, 0x0f, 0x47, 0x65, 0x74, 0x52,
	0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x53, 0x74, 0x61, 0x74, 0x65, 0x12, 0x12, 0x2e, 0x47, 0x52,
	0x50, 0x43, 0x52, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x1a,
	0x19, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x52, 0x61,
	0x69, 0x6c, 0x77, 0x61, 0x79, 0x53, 0x74, 0x61, 0x74, 0x65, 0x22, 0x00, 0x12, 0x34, 0x0a, 0x08,
	0x47, 0x65, 0x74, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x12, 0x12, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52,
	0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x1a, 0x12, 0x2e, 0x47,
	0x52, 0x50, 0x43, 0x52, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x54, 0x72, 0x61, 0x69, 0x6e,
	0x22, 0x00, 0x12, 0x40, 0x0a, 0x0f, 0x47, 0x65, 0x74, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x49, 0x6e,
	0x51, 0x75, 0x65, 0x75, 0x65, 0x12, 0x12, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52, 0x61, 0x69, 0x6c,
	0x77, 0x61, 0x79, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x1a, 0x17, 0x2e, 0x47, 0x52, 0x50, 0x43,
	0x52, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x41, 0x72, 0x72,
	0x61, 0x79, 0x22, 0x00, 0x12, 0x3c, 0x0a, 0x0b, 0x47, 0x65, 0x74, 0x41, 0x6c, 0x6c, 0x54, 0x72,
	0x61, 0x69, 0x6e, 0x12, 0x12, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52, 0x61, 0x69, 0x6c, 0x77, 0x61,
	0x79, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x1a, 0x17, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52, 0x61,
	0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x41, 0x72, 0x72, 0x61, 0x79,
	0x22, 0x00, 0x12, 0x3f, 0x0a, 0x0e, 0x47, 0x65, 0x74, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x4f, 0x6e,
	0x52, 0x61, 0x69, 0x6c, 0x12, 0x12, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52, 0x61, 0x69, 0x6c, 0x77,
	0x61, 0x79, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x1a, 0x17, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52,
	0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x41, 0x72, 0x72, 0x61,
	0x79, 0x22, 0x00, 0x12, 0x4b, 0x0a, 0x10, 0x41, 0x64, 0x64, 0x56, 0x69, 0x72, 0x74, 0x75, 0x61,
	0x6c, 0x54, 0x72, 0x61, 0x69, 0x6e, 0x73, 0x12, 0x21, 0x2e, 0x47, 0x52, 0x50, 0x43, 0x52, 0x61,
	0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x56, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6c, 0x54, 0x72, 0x61,
	0x69, 0x6e, 0x54, 0x65, 0x6d, 0x70, 0x6c, 0x61, 0x74, 0x65, 0x1a, 0x12, 0x2e, 0x47, 0x52, 0x50,
	0x43, 0x52, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x2e, 0x45, 0x6d, 0x70, 0x74, 0x79, 0x22, 0x00,
	0x42, 0x22, 0x5a, 0x20, 0x68, 0x74, 0x74, 0x70, 0x5f, 0x72, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79,
	0x5f, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x2f, 0x72, 0x61, 0x69, 0x6c, 0x77, 0x61, 0x79, 0x5f,
	0x67, 0x72, 0x70, 0x63, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_messages_proto_rawDescOnce sync.Once
	file_messages_proto_rawDescData = file_messages_proto_rawDesc
)

func file_messages_proto_rawDescGZIP() []byte {
	file_messages_proto_rawDescOnce.Do(func() {
		file_messages_proto_rawDescData = protoimpl.X.CompressGZIP(file_messages_proto_rawDescData)
	})
	return file_messages_proto_rawDescData
}

var file_messages_proto_enumTypes = make([]protoimpl.EnumInfo, 1)
var file_messages_proto_msgTypes = make([]protoimpl.MessageInfo, 5)
var file_messages_proto_goTypes = []interface{}{
	(ETrainState)(0),             // 0: GRPCRailway.ETrainState
	(*VirtualTrainTemplate)(nil), // 1: GRPCRailway.VirtualTrainTemplate
	(*TrainArray)(nil),           // 2: GRPCRailway.TrainArray
	(*Train)(nil),                // 3: GRPCRailway.Train
	(*RailwayState)(nil),         // 4: GRPCRailway.RailwayState
	(*Empty)(nil),                // 5: GRPCRailway.Empty
}
var file_messages_proto_depIdxs = []int32{
	3, // 0: GRPCRailway.TrainArray.train_array:type_name -> GRPCRailway.Train
	0, // 1: GRPCRailway.Train.train_state:type_name -> GRPCRailway.ETrainState
	3, // 2: GRPCRailway.RailwayState.trains:type_name -> GRPCRailway.Train
	5, // 3: GRPCRailway.Railway.GetRailwayState:input_type -> GRPCRailway.Empty
	3, // 4: GRPCRailway.Railway.GetTrain:input_type -> GRPCRailway.Train
	5, // 5: GRPCRailway.Railway.GetTrainInQueue:input_type -> GRPCRailway.Empty
	5, // 6: GRPCRailway.Railway.GetAllTrain:input_type -> GRPCRailway.Empty
	5, // 7: GRPCRailway.Railway.GetTrainOnRail:input_type -> GRPCRailway.Empty
	1, // 8: GRPCRailway.Railway.AddVirtualTrains:input_type -> GRPCRailway.VirtualTrainTemplate
	4, // 9: GRPCRailway.Railway.GetRailwayState:output_type -> GRPCRailway.RailwayState
	3, // 10: GRPCRailway.Railway.GetTrain:output_type -> GRPCRailway.Train
	2, // 11: GRPCRailway.Railway.GetTrainInQueue:output_type -> GRPCRailway.TrainArray
	2, // 12: GRPCRailway.Railway.GetAllTrain:output_type -> GRPCRailway.TrainArray
	2, // 13: GRPCRailway.Railway.GetTrainOnRail:output_type -> GRPCRailway.TrainArray
	5, // 14: GRPCRailway.Railway.AddVirtualTrains:output_type -> GRPCRailway.Empty
	9, // [9:15] is the sub-list for method output_type
	3, // [3:9] is the sub-list for method input_type
	3, // [3:3] is the sub-list for extension type_name
	3, // [3:3] is the sub-list for extension extendee
	0, // [0:3] is the sub-list for field type_name
}

func init() { file_messages_proto_init() }
func file_messages_proto_init() {
	if File_messages_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_messages_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*VirtualTrainTemplate); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_messages_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*TrainArray); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_messages_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*Train); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_messages_proto_msgTypes[3].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*RailwayState); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_messages_proto_msgTypes[4].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*Empty); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_messages_proto_rawDesc,
			NumEnums:      1,
			NumMessages:   5,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_messages_proto_goTypes,
		DependencyIndexes: file_messages_proto_depIdxs,
		EnumInfos:         file_messages_proto_enumTypes,
		MessageInfos:      file_messages_proto_msgTypes,
	}.Build()
	File_messages_proto = out.File
	file_messages_proto_rawDesc = nil
	file_messages_proto_goTypes = nil
	file_messages_proto_depIdxs = nil
}
