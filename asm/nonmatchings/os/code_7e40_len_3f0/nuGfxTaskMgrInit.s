.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxTaskMgrInit
/* 7F38 8002CB38 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 7F3C 8002CB3C 24020008 */  addiu     $v0, $zero, 8
/* 7F40 8002CB40 3C01800A */  lui       $at, %hi(D_8009C514)
/* 7F44 8002CB44 A422C514 */  sh        $v0, %lo(D_8009C514)($at)
/* 7F48 8002CB48 24020004 */  addiu     $v0, $zero, 4
/* 7F4C 8002CB4C 3C01800A */  lui       $at, %hi(D_8009C516)
/* 7F50 8002CB50 A422C516 */  sh        $v0, %lo(D_8009C516)($at)
/* 7F54 8002CB54 3C02800A */  lui       $v0, %hi(nuGfxTaskSpool)
/* 7F58 8002CB58 2442A618 */  addiu     $v0, $v0, %lo(nuGfxTaskSpool)
/* 7F5C 8002CB5C AFBF0038 */  sw        $ra, 0x38($sp)
/* 7F60 8002CB60 AFB70034 */  sw        $s7, 0x34($sp)
/* 7F64 8002CB64 AFB60030 */  sw        $s6, 0x30($sp)
/* 7F68 8002CB68 AFB5002C */  sw        $s5, 0x2c($sp)
/* 7F6C 8002CB6C AFB40028 */  sw        $s4, 0x28($sp)
/* 7F70 8002CB70 AFB30024 */  sw        $s3, 0x24($sp)
/* 7F74 8002CB74 AFB20020 */  sw        $s2, 0x20($sp)
/* 7F78 8002CB78 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7F7C 8002CB7C AFB00018 */  sw        $s0, 0x18($sp)
/* 7F80 8002CB80 AC400000 */  sw        $zero, ($v0)
/* 7F84 8002CB84 0C017D00 */  jal       nuGfxDisplayOff
/* 7F88 8002CB88 0000902D */   daddu    $s2, $zero, $zero
/* 7F8C 8002CB8C 3C10800A */  lui       $s0, %hi(D_8009C518)
/* 7F90 8002CB90 2610C518 */  addiu     $s0, $s0, %lo(D_8009C518)
/* 7F94 8002CB94 0200202D */  daddu     $a0, $s0, $zero
/* 7F98 8002CB98 24050005 */  addiu     $a1, $zero, 5
/* 7F9C 8002CB9C 3C068003 */  lui       $a2, %hi(nuGfxTaskMgr)
/* 7FA0 8002CBA0 24C6CA40 */  addiu     $a2, $a2, %lo(nuGfxTaskMgr)
/* 7FA4 8002CBA4 3C02800A */  lui       $v0, %hi(D_8009E6D0)
/* 7FA8 8002CBA8 2442E6D0 */  addiu     $v0, $v0, %lo(D_8009E6D0)
/* 7FAC 8002CBAC AFA20010 */  sw        $v0, 0x10($sp)
/* 7FB0 8002CBB0 2402003C */  addiu     $v0, $zero, 0x3c
/* 7FB4 8002CBB4 0000382D */  daddu     $a3, $zero, $zero
/* 7FB8 8002CBB8 0C019798 */  jal       osCreateThread
/* 7FBC 8002CBBC AFA20014 */   sw       $v0, 0x14($sp)
/* 7FC0 8002CBC0 0C019808 */  jal       osStartThread
/* 7FC4 8002CBC4 0200202D */   daddu    $a0, $s0, $zero
/* 7FC8 8002CBC8 3C17800E */  lui       $s7, %hi(D_800DAC90)
/* 7FCC 8002CBCC 26F7AC90 */  addiu     $s7, $s7, %lo(D_800DAC90)
/* 7FD0 8002CBD0 24160001 */  addiu     $s6, $zero, 1
/* 7FD4 8002CBD4 3C13800E */  lui       $s3, %hi(D_800D9780)
/* 7FD8 8002CBD8 26739780 */  addiu     $s3, $s3, %lo(D_800D9780)
/* 7FDC 8002CBDC 24150100 */  addiu     $s5, $zero, 0x100
/* 7FE0 8002CBE0 24141000 */  addiu     $s4, $zero, 0x1000
/* 7FE4 8002CBE4 3C02800E */  lui       $v0, %hi(D_800D9278)
/* 7FE8 8002CBE8 24429278 */  addiu     $v0, $v0, %lo(D_800D9278)
/* 7FEC 8002CBEC 0040802D */  daddu     $s0, $v0, $zero
/* 7FF0 8002CBF0 26110058 */  addiu     $s1, $s0, 0x58
.L8002CBF4:
/* 7FF4 8002CBF4 3C04B000 */  lui       $a0, 0xb000
/* 7FF8 8002CBF8 34840B70 */  ori       $a0, $a0, 0xb70
/* 7FFC 8002CBFC 3C05B000 */  lui       $a1, 0xb000
/* 8000 8002CC00 34A50C70 */  ori       $a1, $a1, 0xc70
/* 8004 8002CC04 0260302D */  daddu     $a2, $s3, $zero
/* 8008 8002CC08 AE110000 */  sw        $s1, ($s0)
/* 800C 8002CC0C AE170050 */  sw        $s7, 0x50($s0)
/* 8010 8002CC10 AE160010 */  sw        $s6, 0x10($s0)
/* 8014 8002CC14 0C00A5CF */  jal       dma_copy
/* 8018 8002CC18 AE000014 */   sw       $zero, 0x14($s0)
/* 801C 8002CC1C 24020800 */  addiu     $v0, $zero, 0x800
/* 8020 8002CC20 AE02002C */  sw        $v0, 0x2c($s0)
/* 8024 8002CC24 3C02800E */  lui       $v0, %hi(D_800DA040)
/* 8028 8002CC28 2442A040 */  addiu     $v0, $v0, %lo(D_800DA040)
/* 802C 8002CC2C AE020030 */  sw        $v0, 0x30($s0)
/* 8030 8002CC30 24020400 */  addiu     $v0, $zero, 0x400
/* 8034 8002CC34 AE020034 */  sw        $v0, 0x34($s0)
/* 8038 8002CC38 3C02800C */  lui       $v0, %hi(D_800B91D0)
/* 803C 8002CC3C 244291D0 */  addiu     $v0, $v0, %lo(D_800B91D0)
/* 8040 8002CC40 AE020038 */  sw        $v0, 0x38($s0)
/* 8044 8002CC44 3C02800E */  lui       $v0, %hi(D_800D91D0)
/* 8048 8002CC48 244291D0 */  addiu     $v0, $v0, %lo(D_800D91D0)
/* 804C 8002CC4C AE02003C */  sw        $v0, 0x3c($s0)
/* 8050 8002CC50 3C02800C */  lui       $v0, %hi(D_800B8590)
/* 8054 8002CC54 24428590 */  addiu     $v0, $v0, %lo(D_800B8590)
/* 8058 8002CC58 AE020048 */  sw        $v0, 0x48($s0)
/* 805C 8002CC5C 24020C10 */  addiu     $v0, $zero, 0xc10
/* 8060 8002CC60 AE130018 */  sw        $s3, 0x18($s0)
/* 8064 8002CC64 AE15001C */  sw        $s5, 0x1c($s0)
/* 8068 8002CC68 AE140024 */  sw        $s4, 0x24($s0)
/* 806C 8002CC6C AE02004C */  sw        $v0, 0x4c($s0)
/* 8070 8002CC70 26100058 */  addiu     $s0, $s0, 0x58
/* 8074 8002CC74 26520001 */  addiu     $s2, $s2, 1
/* 8078 8002CC78 2E42000A */  sltiu     $v0, $s2, 0xa
/* 807C 8002CC7C 1440FFDD */  bnez      $v0, .L8002CBF4
/* 8080 8002CC80 26310058 */   addiu    $s1, $s1, 0x58
/* 8084 8002CC84 3C02800E */  lui       $v0, %hi(D_800D9278)
/* 8088 8002CC88 24429278 */  addiu     $v0, $v0, %lo(D_800D9278)
/* 808C 8002CC8C AC420318 */  sw        $v0, 0x318($v0)
/* 8090 8002CC90 8FBF0038 */  lw        $ra, 0x38($sp)
/* 8094 8002CC94 8FB70034 */  lw        $s7, 0x34($sp)
/* 8098 8002CC98 8FB60030 */  lw        $s6, 0x30($sp)
/* 809C 8002CC9C 8FB5002C */  lw        $s5, 0x2c($sp)
/* 80A0 8002CCA0 8FB40028 */  lw        $s4, 0x28($sp)
/* 80A4 8002CCA4 8FB30024 */  lw        $s3, 0x24($sp)
/* 80A8 8002CCA8 8FB20020 */  lw        $s2, 0x20($sp)
/* 80AC 8002CCAC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 80B0 8002CCB0 8FB00018 */  lw        $s0, 0x18($sp)
/* 80B4 8002CCB4 3C01800A */  lui       $at, %hi(D_8009C510)
/* 80B8 8002CCB8 AC22C510 */  sw        $v0, %lo(D_8009C510)($at)
/* 80BC 8002CCBC 03E00008 */  jr        $ra
/* 80C0 8002CCC0 27BD0040 */   addiu    $sp, $sp, 0x40
