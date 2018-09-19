if ln f1.txt f1.txt.lock; then
  sh ex2.sh
  rm f1.txt.lock;
fi