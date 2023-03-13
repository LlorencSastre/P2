project ('P2-Detector de actividad vocal', 'c')

exe = 'vad'
src = ['src/main_vad.c', 'src/vad.c', 'src/pav_analysis.c']
lib = ['-lm', '-lsndfile']

executable(exe,sources : src, link_args : lib)
