#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>

void die(const char* message) {
  fprintf(stderr, "%s\n", message);
  exit(1);
}
 
int main(int argc, char* argv[]) {

  char *input_filename = "/Users/kbn/Dropbox/Kapper og Jepper/Filer med fejl/Borgen error.mov";

  // This call is necessarily done once in your app to initialize
  // libavformat to register all the muxers, demuxers and protocols.
  av_register_all();

  // A media container
  AVFormatContext* container = 0;

  if (avformat_open_input(&container, input_filename, NULL, NULL) < 0) {
    die("Could not open file");
  }

  if (avformat_find_stream_info(container, NULL) < 0) {
    die("Could not find file info");
  }

  AVStream *stream = NULL;

  // To find the first audio stream. This process may not be necessary
  // if you can gurarantee that the container contains only the desired
  // audio stream
  int i;
  for (i = 0; i < container->nb_streams; i++) {
    if (container->streams[i]->codec->codec_type == AV_CODEC_ID_NONE) {
      stream = container->streams[i];
      break;
    }
  }

  if (stream == NULL) {
    die("Could not find an video stream");
  }
  
  printf("%s\n", stream->codec->codec_name); // Apple ProRes 422 (HQ)
}