pipeline {
    agent any

    stages {
        stage('Setup') {
            steps {
                sh 'cp /usr/local/etc/roms/baserom_pm.z64 baserom.z64'
                sh 'make setup'
            }
        }
        stage('Build') {
            steps {
                echo 'Building...'
                sh 'make -j'
            }
        }
        stage('Report Progress') {
            when {
                branch 'master'
            }
            steps {
                sh 'python3 progress.py --csv >> /var/www/papermar.io/html/reports/progress.csv'
            }
        }
    }
    post {
        always {
            cleanWs()
        }
    }
}
