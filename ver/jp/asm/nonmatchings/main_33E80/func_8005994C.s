.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005994C
/* 34D4C 8005994C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 34D50 80059950 2402000E */  addiu     $v0, $zero, 0xe
/* 34D54 80059954 3C03800A */  lui       $v1, %hi(D_800A1FD0)
/* 34D58 80059958 24631FD0 */  addiu     $v1, $v1, %lo(D_800A1FD0)
/* 34D5C 8005995C AFBF001C */  sw        $ra, 0x1c($sp)
/* 34D60 80059960 AFB00018 */  sw        $s0, 0x18($sp)
.L80059964:
/* 34D64 80059964 AC600000 */  sw        $zero, ($v1)
/* 34D68 80059968 2442FFFF */  addiu     $v0, $v0, -1
/* 34D6C 8005996C 0441FFFD */  bgez      $v0, .L80059964
/* 34D70 80059970 2463FFE0 */   addiu    $v1, $v1, -0x20
/* 34D74 80059974 2402005F */  addiu     $v0, $zero, 0x5f
/* 34D78 80059978 3C03800B */  lui       $v1, %hi(D_800B44F4)
/* 34D7C 8005997C 246344F4 */  addiu     $v1, $v1, %lo(D_800B44F4)
.L80059980:
/* 34D80 80059980 AC600000 */  sw        $zero, ($v1)
/* 34D84 80059984 2442FFFF */  addiu     $v0, $v0, -1
/* 34D88 80059988 0441FFFD */  bgez      $v0, .L80059980
/* 34D8C 8005998C 2463FFFC */   addiu    $v1, $v1, -4
/* 34D90 80059990 0C019A4C */  jal       func_80066930
/* 34D94 80059994 00000000 */   nop
/* 34D98 80059998 3C0300FF */  lui       $v1, 0xff
/* 34D9C 8005999C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 34DA0 800599A0 24040010 */  addiu     $a0, $zero, 0x10
/* 34DA4 800599A4 0000282D */  daddu     $a1, $zero, $zero
/* 34DA8 800599A8 3C10E020 */  lui       $s0, %hi(D_E0200000)
/* 34DAC 800599AC 26100000 */  addiu     $s0, $s0, %lo(D_E0200000)
/* 34DB0 800599B0 0200302D */  daddu     $a2, $s0, $zero
/* 34DB4 800599B4 2402FFFF */  addiu     $v0, $zero, -1
/* 34DB8 800599B8 3C07801A */  lui       $a3, %hi(D_801A6000)
/* 34DBC 800599BC 24E76000 */  addiu     $a3, $a3, %lo(D_801A6000)
/* 34DC0 800599C0 00E33824 */  and       $a3, $a3, $v1
/* 34DC4 800599C4 AFA20010 */  sw        $v0, 0x10($sp)
/* 34DC8 800599C8 0C0199DC */  jal       func_80066770
/* 34DCC 800599CC AFA20014 */   sw       $v0, 0x14($sp)
/* 34DD0 800599D0 3C040033 */  lui       $a0, 0x33
/* 34DD4 800599D4 2484DDD0 */  addiu     $a0, $a0, -0x2230
/* 34DD8 800599D8 3C050033 */  lui       $a1, 0x33
/* 34DDC 800599DC 24A5E710 */  addiu     $a1, $a1, -0x18f0
/* 34DE0 800599E0 0C00A5BF */  jal       func_800296FC
/* 34DE4 800599E4 0200302D */   daddu    $a2, $s0, $zero
/* 34DE8 800599E8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 34DEC 800599EC 8FB00018 */  lw        $s0, 0x18($sp)
/* 34DF0 800599F0 03E00008 */  jr        $ra
/* 34DF4 800599F4 27BD0020 */   addiu    $sp, $sp, 0x20
