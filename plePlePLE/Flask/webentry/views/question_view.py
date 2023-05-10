from flask import Blueprint, render_template, request, url_for
from ..models import Question
from .. import db

from werkzeug.utils import redirect

bp = Blueprint('question', __name__, url_prefix='/question')

@bp.route('/list')
def _lists():
    question_list = Question.query.order_by(Question.create_date.desc())
    return render_template('question/question_list.html', question_list=question_list)


@bp.route('/detail/<int:question_id>/')
def detail(question_id):
    question = Question.query.get_or_404(question_id)
    return render_template('question/question_detail.html', question=question)

@bp.route('/modify/<int:question_id>/')
def mdetail(question_id):
    question = Question.query.get_or_404(question_id)
    return render_template('question/question_modify.html', question=question)

@bp.route('/modify/<int:question_id>/submit', methods=('POST', ))
def modify(question_id):
    question = Question.query.get_or_404(question_id)
    content = request.form['content']
    question.content = content
    db.session.commit()
    return redirect(url_for('question.detail', question_id=question_id))