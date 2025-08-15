pipeline {
    agent {
        label 'papermario'
    }

    stages {
        stage('Setup') {
            steps {
                sh 'cp /usr/local/etc/roms/papermario.us.z64 ver/us/baserom.z64'
                sh 'cp /usr/local/etc/roms/papermario.jp.z64 ver/jp/baserom.z64'
                sh 'cp /usr/local/etc/roms/papermario.ique.z64 ver/ique/baserom.z64'
                sh 'cp /usr/local/etc/roms/papermario.pal.z64 ver/pal/baserom.z64'
                sh 'curl -L "https://github.com/pmret/gcc-papermario/releases/download/master/linux.tar.gz" | tar zx -C tools/build/cc/gcc'
                sh 'curl -L "https://github.com/pmret/binutils-papermario/releases/download/master/linux.tar.gz" | tar zx -C tools/build/cc/gcc'
                sh 'curl -L "https://github.com/decompals/ido-static-recomp/releases/download/v0.2/ido-5.3-recomp-ubuntu-latest.tar.gz" | tar zx -C tools/build/cc/ido5.3'
                sh 'curl -L "https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-linux.tar.gz" | tar zx -C tools/build/cc/gcc2.7.2'
                sh 'curl -L "https://github.com/decompals/mips-binutils-2.6/releases/download/main/binutils-2.6-linux.tar.gz" | tar zx -C tools/build/cc/gcc2.7.2'
                sh 'curl -L "https://github.com/decompals/mips-binutils-egcs-2.9.5/releases/latest/download/mips-binutils-egcs-2.9.5-linux.tar.gz" | tar zx -C tools/build/cc/egcs'
                sh 'curl -L "https://github.com/decompals/mips-gcc-egcs-2.91.66/releases/latest/download/mips-gcc-egcs-2.91.66-linux.tar.gz" | tar zx -C tools/build/cc/egcs'
                sh 'pip install -U -r tools/configure/requirements.txt --break-system-packages'
                sh 'cargo install pigment64'
                sh 'cargo install crunch64-cli'
                sh './configure'
            }
        }
        stage('Build') {
            steps {
                sh "bash -o pipefail -c 'ninja 2>&1 | tee build_log.txt'"
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
                        def us_progress = sh(returnStdout: true, script: "python3 progress.py us --pr-comment").trim()
                        def jp_progress = sh(returnStdout: true, script: "python3 progress.py jp --pr-comment").trim()
                        def ique_progress = sh(returnStdout: true, script: "python3 progress.py ique --pr-comment").trim()
                        def pal_progress = sh(returnStdout: true, script: "python3 progress.py pal --pr-comment").trim()
                        def warnings = sh(returnStdout: true, script: "./tools/warnings_count/compare_warnings.py --pr-message").trim()
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
                sh 'mkdir reports'

                sh 'python3 progress.py us --csv >> reports/progress_us.csv'
                sh 'python3 progress.py us --shield-json > reports/progress_us_shield.json'

                sh 'python3 progress.py jp --csv >> reports/progress_jp.csv'
                sh 'python3 progress.py jp --shield-json > reports/progress_jp_shield.json'

                sh 'python3 progress.py ique --csv >> reports/progress_ique.csv'
                sh 'python3 progress.py ique --shield-json > reports/progress_ique_shield.json'

                sh 'python3 progress.py pal --csv >> reports/progress_pal.csv'
                sh 'python3 progress.py pal --shield-json > reports/progress_pal_shield.json'

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
        stage('Build (shift US)') {
            steps {
                sh './configure --shift us'
                sh 'ninja'
            }
        }
    }
    post {
        always {
            cleanWs()
        }
    }
}
