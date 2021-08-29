.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244224_9DB244
/* 9DB244 80244224 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9DB248 80244228 AFB00010 */  sw        $s0, 0x10($sp)
/* 9DB24C 8024422C 0080802D */  daddu     $s0, $a0, $zero
/* 9DB250 80244230 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9DB254 80244234 8E02000C */  lw        $v0, 0xc($s0)
/* 9DB258 80244238 0C0B1EAF */  jal       evt_get_variable
/* 9DB25C 8024423C 8C450000 */   lw       $a1, ($v0)
/* 9DB260 80244240 2442FFFF */  addiu     $v0, $v0, -1
/* 9DB264 80244244 3C048025 */  lui       $a0, %hi(D_80252784_9E97A4)
/* 9DB268 80244248 24842784 */  addiu     $a0, $a0, %lo(D_80252784_9E97A4)
/* 9DB26C 8024424C 000218C0 */  sll       $v1, $v0, 3
/* 9DB270 80244250 00621823 */  subu      $v1, $v1, $v0
/* 9DB274 80244254 00031880 */  sll       $v1, $v1, 2
/* 9DB278 80244258 00641821 */  addu      $v1, $v1, $a0
/* 9DB27C 8024425C 8C620000 */  lw        $v0, ($v1)
/* 9DB280 80244260 AE020084 */  sw        $v0, 0x84($s0)
/* 9DB284 80244264 8C620004 */  lw        $v0, 4($v1)
/* 9DB288 80244268 AE020088 */  sw        $v0, 0x88($s0)
/* 9DB28C 8024426C 8C630008 */  lw        $v1, 8($v1)
/* 9DB290 80244270 AE03008C */  sw        $v1, 0x8c($s0)
/* 9DB294 80244274 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9DB298 80244278 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DB29C 8024427C 24020002 */  addiu     $v0, $zero, 2
/* 9DB2A0 80244280 03E00008 */  jr        $ra
/* 9DB2A4 80244284 27BD0018 */   addiu    $sp, $sp, 0x18
