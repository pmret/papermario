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
                sh './configure --no-ccache'
            }
        }
        stage('Build') {
            steps {
                sh 'ninja 2>&1 | tee build_log.txt'
            }
        }
        stage("Comment") {
            when {
                not {
                    branch 'master'
                }
            }
            steps {
                script {
                    if (env.CHANGE_ID) {
                        def us_progress = sh(returnStdout: true, script: "python3 progress.py us --pr-comment").trim()
                        def jp_progress = sh(returnStdout: true, script: "python3 progress.py jp --pr-comment").trim()
                        def warnings = sh(returnStdout: true, script: "./tools/warnings_count/check_new_warnings.sh --jenkins").trim()
                        def comment_id = -1

                        for (comment in pullRequest.comments) {
                            if (comment.user == "BowserSlug") {
                                comment_id = comment.id
                            }
                        }

                        def message = "${us_progress}\n${jp_progress}\n${warnings}"

                        if (message != "\n\n") {
                            if (comment_id == -1) {
                                pullRequest.comment(message)
                            } else {
                                pullRequest.editComment(comment_id, message)
                            }
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

                sh './tools/warnings_count/update_current_warnings.sh'
                sh 'cp tools/warnings_count/warnings.txt reports/warnings.txt'

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

                sh 'cat reports/warnings.txt > /var/www/papermar.io/html/reports/warnings.txt'
            }
        }
    }
    post {
        always {
            cleanWs()
        }
    }
}
