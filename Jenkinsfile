pipeline {
    agent {
        label 'papermario'
    }

    stages {
        stage('Build') {
            matrix {
                axes {
                    axis {
                        name 'VERSION'
                        values 'us', 'jp', 'ique', 'pal'
                    }
                }

                stages {
                    stage('Setup') {
                        steps {
                            sh 'curl -L "https://github.com/pmret/gcc-papermario/releases/download/master/linux.tar.gz" | tar zx -C tools/build/cc/gcc'
                            sh 'curl -L "https://github.com/pmret/binutils-papermario/releases/download/master/linux.tar.gz" | tar zx -C tools/build/cc/gcc'
                            sh 'curl -L "https://github.com/decompals/ido-static-recomp/releases/download/v0.2/ido-5.3-recomp-ubuntu-latest.tar.gz" | tar zx -C tools/build/cc/ido5.3'
                            sh 'curl -L "https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-linux.tar.gz" | tar zx -C tools/build/cc/gcc2.7.2'
                            sh 'curl -L "https://github.com/decompals/mips-binutils-2.6/releases/download/main/binutils-2.6-linux.tar.gz" | tar zx -C tools/build/cc/gcc2.7.2'

                            sh 'pip install -U -r requirements.txt'

                            sh 'cp /usr/local/etc/roms/papermario.${VERSION}.z64 ver/${VERSION}/baserom.z64'
                            sh './configure'
                        }
                    }
                    stage('Build') {
                        steps {
                            sh "bash -o pipefail -c 'ninja 2>&1 | tee build_log_${VERSION}.txt'"
                            sh 'mkdir reports'
                            sh 'python3 progress.py ${VERSION} --pr-comment >> reports/progress_${VERSION}.txt'
                            sh 'python3 progress.py ${VERSION} --csv >> reports/progress_${VERSION}.csv'
                            sh 'python3 progress.py ${VERSION} --shield-json > reports/progress_${VERSION}_shield.json'
                        }
                    }
                }
            }
        }
        stage("Merge output") {
            steps {
                sh 'cat build_log_us.txt >> build_log.txt'
                sh 'cat build_log_jp.txt >> build_log.txt'
                sh 'cat build_log_ique.txt >> build_log.txt'
                sh 'cat build_log_pal.txt >> build_log.txt'
            }
        }
        stage("Comment") {
            when {
                not {
                    branch 'main'
                }
            }
            steps {
                script {
                    if (env.CHANGE_ID) {
                        def us_progress = sh(returnStdout: true, script: "cat reports/progress_us.txt").trim()
                        def jp_progress = sh(returnStdout: true, script: "cat reports/progress_jp.txt").trim()
                        def ique_progress = sh(returnStdout: true, script: "cat reports/progress_ique.txt").trim()
                        def pal_progress = sh(returnStdout: true, script: "cat reports/progress_pal.txt").trim()
                        def warnings = sh(returnStdout: true, script: "./tools/warnings_count/check_new_warnings.sh --jenkins").trim()
                        def comment_id = -1

                        for (comment in pullRequest.comments) {
                            if (comment.user == "BowserSlug") {
                                comment_id = comment.id
                            }
                        }

                        def message = "${us_progress}\n${jp_progress}\n${ique_progress}\n${pal_progress}\n${warnings}"

                        if (message != "\n\n\n\n") {
                            if (comment_id == -1) {
                                echo message
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
                branch 'main'
            }
            steps {
                sh 'cat build_log.txt | grep warning | sort > tools/warnings_count/warnings.txt'
                sh 'cp tools/warnings_count/warnings.txt reports/warnings.txt'

                stash includes: 'reports/*', name: 'reports'
            }
        }
        stage('Update Progress') {
            when {
                branch 'main'
            }
            agent {
                label 'pm_website'
            }
            steps {
                unstash 'reports'
                sh 'cat reports/progress_us.csv >> /var/www/papermar.io/html/reports/progress_us.csv'
                sh 'cat reports/progress_us_shield.json > /var/www/papermar.io/html/reports/progress_us_shield.json'

                sh 'cat reports/progress_jp.csv >> /var/www/papermar.io/html/reports/progress_jp.csv'
                sh 'cat reports/progress_jp_shield.json > /var/www/papermar.io/html/reports/progress_jp_shield.json'

                sh 'cat reports/progress_ique.csv >> /var/www/papermar.io/html/reports/progress_ique.csv'
                sh 'cat reports/progress_ique_shield.json > /var/www/papermar.io/html/reports/progress_ique_shield.json'

                sh 'cat reports/progress_pal.csv >> /var/www/papermar.io/html/reports/progress_pal.csv'
                sh 'cat reports/progress_pal_shield.json > /var/www/papermar.io/html/reports/progress_pal_shield.json'

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
