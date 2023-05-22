FROM python:3.10

WORKDIR /app

COPY requirements.txt requirements.txt

RUN  mkdir -p /app/bot/static/ \
     && pip install --upgrade pip --no-cache-dir \
     && pip install -r requirements.txt

COPY . .


CMD ["python", "-m", "bot"]
