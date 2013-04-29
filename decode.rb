require 'ruby-ffmpeg'

filepath = "/Users/kbn/Dropbox/Kapper\ og\ Jepper/Filer\ med\ fejl/Borgen\ error.mov"

puts 'starting'
io = File.open(filepath)
reader = FFMPEG::Reader.open(io)
video_stream = reader.streams.select { |s| s.type == :video }.first
raise "File does not contain a video stream" unless video_stream
puts "frame: #{video_stream.decode}"