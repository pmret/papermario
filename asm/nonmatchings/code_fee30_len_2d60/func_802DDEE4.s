.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DDEE4
/* 100FD4 802DDEE4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 100FD8 802DDEE8 AFB40030 */  sw        $s4, 0x30($sp)
/* 100FDC 802DDEEC 00A0A02D */  daddu     $s4, $a1, $zero
/* 100FE0 802DDEF0 AFB50034 */  sw        $s5, 0x34($sp)
/* 100FE4 802DDEF4 00041040 */  sll       $v0, $a0, 1
/* 100FE8 802DDEF8 00441021 */  addu      $v0, $v0, $a0
/* 100FEC 802DDEFC 00021080 */  sll       $v0, $v0, 2
/* 100FF0 802DDF00 AFBF0044 */  sw        $ra, 0x44($sp)
/* 100FF4 802DDF04 AFBE0040 */  sw        $fp, 0x40($sp)
/* 100FF8 802DDF08 AFB7003C */  sw        $s7, 0x3c($sp)
/* 100FFC 802DDF0C AFB60038 */  sw        $s6, 0x38($sp)
/* 101000 802DDF10 AFB3002C */  sw        $s3, 0x2c($sp)
/* 101004 802DDF14 AFB20028 */  sw        $s2, 0x28($sp)
/* 101008 802DDF18 AFB10024 */  sw        $s1, 0x24($sp)
/* 10100C 802DDF1C AFB00020 */  sw        $s0, 0x20($sp)
/* 101010 802DDF20 AFA70054 */  sw        $a3, 0x54($sp)
/* 101014 802DDF24 3C01802E */  lui       $at, %hi(D_802DF588)
/* 101018 802DDF28 00220821 */  addu      $at, $at, $v0
/* 10101C 802DDF2C 8C22F588 */  lw        $v0, %lo(D_802DF588)($at)
/* 101020 802DDF30 8FBE0064 */  lw        $fp, 0x64($sp)
/* 101024 802DDF34 10400024 */  beqz      $v0, .L802DDFC8
/* 101028 802DDF38 00C0A82D */   daddu    $s5, $a2, $zero
/* 10102C 802DDF3C 0040882D */  daddu     $s1, $v0, $zero
/* 101030 802DDF40 8E230000 */  lw        $v1, ($s1)
/* 101034 802DDF44 2402FFFF */  addiu     $v0, $zero, -1
/* 101038 802DDF48 1062001F */  beq       $v1, $v0, .L802DDFC8
/* 10103C 802DDF4C 0000902D */   daddu    $s2, $zero, $zero
/* 101040 802DDF50 0040982D */  daddu     $s3, $v0, $zero
/* 101044 802DDF54 3C171000 */  lui       $s7, 0x1000
/* 101048 802DDF58 3C160FFF */  lui       $s6, 0xfff
/* 10104C 802DDF5C 36D6FFFF */  ori       $s6, $s6, 0xffff
.L802DDF60:
/* 101050 802DDF60 12930003 */  beq       $s4, $s3, .L802DDF70
/* 101054 802DDF64 8E300000 */   lw       $s0, ($s1)
/* 101058 802DDF68 56540014 */  bnel      $s2, $s4, .L802DDFBC
/* 10105C 802DDF6C 26310004 */   addiu    $s1, $s1, 4
.L802DDF70:
/* 101060 802DDF70 8FA8005C */  lw        $t0, 0x5c($sp)
/* 101064 802DDF74 9204004F */  lbu       $a0, 0x4f($s0)
/* 101068 802DDF78 8FA60054 */  lw        $a2, 0x54($sp)
/* 10106C 802DDF7C 8FA70058 */  lw        $a3, 0x58($sp)
/* 101070 802DDF80 AFA80010 */  sw        $t0, 0x10($sp)
/* 101074 802DDF84 8FA80060 */  lw        $t0, 0x60($sp)
/* 101078 802DDF88 02A0282D */  daddu     $a1, $s5, $zero
/* 10107C 802DDF8C AFBE0018 */  sw        $fp, 0x18($sp)
/* 101080 802DDF90 0C04EAA7 */  jal       func_8013AA9C
/* 101084 802DDF94 AFA80014 */   sw       $t0, 0x14($sp)
/* 101088 802DDF98 12A00004 */  beqz      $s5, .L802DDFAC
/* 10108C 802DDF9C 00000000 */   nop
/* 101090 802DDFA0 8E02004C */  lw        $v0, 0x4c($s0)
/* 101094 802DDFA4 080B77ED */  j         .L802DDFB4
/* 101098 802DDFA8 00571025 */   or       $v0, $v0, $s7
.L802DDFAC:
/* 10109C 802DDFAC 8E02004C */  lw        $v0, 0x4c($s0)
/* 1010A0 802DDFB0 00561024 */  and       $v0, $v0, $s6
.L802DDFB4:
/* 1010A4 802DDFB4 AE02004C */  sw        $v0, 0x4c($s0)
/* 1010A8 802DDFB8 26310004 */  addiu     $s1, $s1, 4
.L802DDFBC:
/* 1010AC 802DDFBC 8E220000 */  lw        $v0, ($s1)
/* 1010B0 802DDFC0 1453FFE7 */  bne       $v0, $s3, .L802DDF60
/* 1010B4 802DDFC4 26520001 */   addiu    $s2, $s2, 1
.L802DDFC8:
/* 1010B8 802DDFC8 8FBF0044 */  lw        $ra, 0x44($sp)
/* 1010BC 802DDFCC 8FBE0040 */  lw        $fp, 0x40($sp)
/* 1010C0 802DDFD0 8FB7003C */  lw        $s7, 0x3c($sp)
/* 1010C4 802DDFD4 8FB60038 */  lw        $s6, 0x38($sp)
/* 1010C8 802DDFD8 8FB50034 */  lw        $s5, 0x34($sp)
/* 1010CC 802DDFDC 8FB40030 */  lw        $s4, 0x30($sp)
/* 1010D0 802DDFE0 8FB3002C */  lw        $s3, 0x2c($sp)
/* 1010D4 802DDFE4 8FB20028 */  lw        $s2, 0x28($sp)
/* 1010D8 802DDFE8 8FB10024 */  lw        $s1, 0x24($sp)
/* 1010DC 802DDFEC 8FB00020 */  lw        $s0, 0x20($sp)
/* 1010E0 802DDFF0 03E00008 */  jr        $ra
/* 1010E4 802DDFF4 27BD0048 */   addiu    $sp, $sp, 0x48
