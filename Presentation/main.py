import chatterbot
import logging
from flask import Flask, request

logging.basicConfig(level=logging.INFO)

bot = chatterbot.chatterbot.ChatBot("Brain", logic_adapters=[
    'chatterbot.logic.BestMatch',
    # 'chatterbot.logic.NeuralAdapter1',
    # 'chatterbot.logic.TimeLogicAdapter',
    # 'chatterbot.logic.UnitConversion',
    'chatterbot.logic.MathematicalEvaluation'
])

app = Flask(__name__)


@app.route('/getResponse', methods=['GET', 'POST'])
def getresponse():
    if request.method == 'POST':
        question = request.form['query']
        personName = request.form['user']
        if personName == '':
            personName = "unknown"
        return "hi  " + personName + " : " + bot.get_response(question, conversation=personName).text
    else:
        return "Get request received"


if __name__=="__main__":
    app.run(host='localhost', port=5003, debug=True)
