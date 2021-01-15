pipeline {
    agent any

    stages {
        stage('Setup') {
            steps {
                sh './configure.py --baserom /usr/local/etc/roms/baserom_pm.z64'
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
