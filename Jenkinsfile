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
    }
    post {
        always {
            cleanWs()
        }
    }
}
