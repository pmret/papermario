pipeline {
    agent {
        label 'papermario'
    }

    stages {
        stage('Setup') {
            steps {
                sh 'cp /usr/local/etc/roms/papermario.us.z64 ver/us/baserom.z64'
                sh 'cp /usr/local/etc/roms/papermario.jp.z64 ver/jp/baserom.z64'
                sh 'curl -L "https://github.com/pmret/gcc-papermario/releases/download/master/linux.tar.gz" | tar zx -C tools/build/cc/gcc'
                sh 'curl -L "https://github.com/pmret/binutils-papermario/releases/download/master/linux.tar.gz" | tar zx -C tools/build/cc/gcc'
                sh './configure'
            }
        }
        stage('Build') {
            steps {
                sh 'ninja'
            }
        }
        stage("Comment") {
            steps {
                script {
                    if (env.CHANGE_ID) {
                        def us_progress = sh(returnStdout: true, script: "python3 progress.py us --pr-comment").trim()
                        def jp_progress = sh(returnStdout: true, script: "python3 progress.py jp --pr-comment").trim()
                        def comment_id = -1

                        for (comment in pullRequest.comments) {
                            if (comment.user == "BowserSlug") {
                                comment_id = comment.id
                            }
                        }

                        def message = "This PR:\n- ${us_progress}\n- ${jp_progress}"

                        if (comment_id == -1) {
                            pullRequest.comment(message)
                        } else {
                            pullRequest.editComment(comment_id, message)
                        }

                    }
                }
            }
        }
        stage('Report Progress') {
            when {
                branch 'master'
            }
            steps {
                sh 'mkdir reports'

                sh 'python3 progress.py us --csv >> reports/progress_us.csv'
                sh 'python3 progress.py us --shield-json > reports/progress_us_shield.json'

                sh 'python3 progress.py jp --csv >> reports/progress_jp.csv'
                sh 'python3 progress.py jp --shield-json > reports/progress_jp_shield.json'

                stash includes: 'reports/*', name: 'reports'
            }
        }
        stage('Update Progress') {
            when {
                branch 'master'
            }
            agent {
                label 'master'
            }
            steps {
                unstash 'reports'
                sh 'cat reports/progress_us.csv >> /var/www/papermar.io/html/reports/progress_us.csv'
                sh 'cat reports/progress_us_shield.json > /var/www/papermar.io/html/reports/progress_us_shield.json'

                sh 'cat reports/progress_jp.csv >> /var/www/papermar.io/html/reports/progress_jp.csv'
                sh 'cat reports/progress_jp_shield.json > /var/www/papermar.io/html/reports/progress_jp_shield.json'
            }
        }
    }
    post {
        always {
            cleanWs()
        }
    }
}
