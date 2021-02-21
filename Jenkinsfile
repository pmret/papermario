def agentLabel
if (BRANCH_NAME == "master") {
    agentLabel = "master"
} else {
    agentLabel = "papermario"
}

pipeline {
    agent {
        label agentLabel
    }

    stages {
        stage('Setup') {
            steps {
                sh 'cp /usr/local/etc/roms/papermario.us.z64 ver/us/baserom.z64'
                sh 'cp /usr/local/etc/roms/papermario.jp.z64 ver/jp/baserom.z64'
                sh './configure.py'
            }
        }
        stage('Build') {
            steps {
                sh 'ninja'
            }
        }
        stage('Report Progress') {
            when {
                branch 'master'
            }
            steps {
                sh 'python3 progress.py us --csv >> /var/www/papermar.io/html/reports/progress_us.csv'
                sh 'python3 progress.py us --shield-json > /var/www/papermar.io/html/reports/progress_us_shield.json'

                sh 'python3 progress.py jp --csv >> /var/www/papermar.io/html/reports/progress_jp.csv'
                sh 'python3 progress.py jp --shield-json > /var/www/papermar.io/html/reports/progress_jp_shield.json'
            }
        }
    }
    post {
        always {
            cleanWs()
        }
    }
}
