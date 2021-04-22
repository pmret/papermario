.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044D64
/* 20164 80044D64 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 20168 80044D68 AFB10014 */  sw        $s1, 0x14($sp)
/* 2016C 80044D6C 0080882D */  daddu     $s1, $a0, $zero
/* 20170 80044D70 AFBF0020 */  sw        $ra, 0x20($sp)
/* 20174 80044D74 AFB3001C */  sw        $s3, 0x1c($sp)
/* 20178 80044D78 AFB20018 */  sw        $s2, 0x18($sp)
/* 2017C 80044D7C AFB00010 */  sw        $s0, 0x10($sp)
/* 20180 80044D80 8E30000C */  lw        $s0, 0xc($s1)
/* 20184 80044D84 8E330148 */  lw        $s3, 0x148($s1)
/* 20188 80044D88 8E050000 */  lw        $a1, ($s0)
/* 2018C 80044D8C 0C0B1EAF */  jal       func_802C7ABC
/* 20190 80044D90 26100004 */   addiu    $s0, $s0, 4
/* 20194 80044D94 0040902D */  daddu     $s2, $v0, $zero
/* 20198 80044D98 8E050000 */  lw        $a1, ($s0)
/* 2019C 80044D9C 0C0B1EAF */  jal       func_802C7ABC
/* 201A0 80044DA0 0220202D */   daddu    $a0, $s1, $zero
/* 201A4 80044DA4 0040802D */  daddu     $s0, $v0, $zero
/* 201A8 80044DA8 2402FFFF */  addiu     $v0, $zero, -1
/* 201AC 80044DAC 16420002 */  bne       $s2, $v0, .L80044DB8
/* 201B0 80044DB0 00000000 */   nop
/* 201B4 80044DB4 86720008 */  lh        $s2, 8($s3)
.L80044DB8:
/* 201B8 80044DB8 0C00FA6A */  jal       func_8003E9A8
/* 201BC 80044DBC 0240202D */   daddu    $a0, $s2, $zero
/* 201C0 80044DC0 0040982D */  daddu     $s3, $v0, $zero
/* 201C4 80044DC4 8E620038 */  lw        $v0, 0x38($s3)
/* 201C8 80044DC8 50400005 */  beql      $v0, $zero, .L80044DE0
/* 201CC 80044DCC AE700020 */   sw       $s0, 0x20($s3)
/* 201D0 80044DD0 8E640050 */  lw        $a0, 0x50($s3)
/* 201D4 80044DD4 0C0B102B */  jal       func_802C40AC
/* 201D8 80044DD8 00000000 */   nop
/* 201DC 80044DDC AE700020 */  sw        $s0, 0x20($s3)
.L80044DE0:
/* 201E0 80044DE0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 201E4 80044DE4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 201E8 80044DE8 8FB20018 */  lw        $s2, 0x18($sp)
/* 201EC 80044DEC 8FB10014 */  lw        $s1, 0x14($sp)
/* 201F0 80044DF0 8FB00010 */  lw        $s0, 0x10($sp)
/* 201F4 80044DF4 24020002 */  addiu     $v0, $zero, 2
/* 201F8 80044DF8 03E00008 */  jr        $ra
/* 201FC 80044DFC 27BD0028 */   addiu    $sp, $sp, 0x28
