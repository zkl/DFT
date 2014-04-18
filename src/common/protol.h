#ifndef PROTOL_H
#define PROTOL_H

#define PROTOL_MAX_BUF_SIZE 1024

typedef struct _proto_stream_t_
{
	int type; // 数据流，和文件流

}proto_stream_t;

typedef struct _proto_stream_node_t_
{
	int type; // 数据流，和文件流

}proto_stream_node_t;

typedef enum _proto_cmd_t_
{
}proto_cmd_t;

typedef struct _proto_addr_t_
{
	short sport;
	short dprot;
	unsigned long saddr;
	unsigned long daddr;
}proto_addr_t;

typedef struct _proto_t_
{
	int index;
	proto_addr_t addr;
	proto_cmd_t cmd;
	char data[PROTOL_MAX_BUF_SIZE];
}proto_t;

void proto_stream_open();
void proto_stream_close();
void proto_stream_write();
void proto_stream_read();
void proto_stream_write_node(); // 读取流块
void proto_stream_read_node();  // 写入流块

void proto_parse();
void proto_serialize();

#endif
