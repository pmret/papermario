.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242274_E17FF4
/* E17FF4 80242274 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E17FF8 80242278 0000202D */  daddu     $a0, $zero, $zero
/* E17FFC 8024227C AFBF0014 */  sw        $ra, 0x14($sp)
/* E18000 80242280 0C00FB3A */  jal       get_enemy
/* E18004 80242284 AFB00010 */   sw       $s0, 0x10($sp)
/* E18008 80242288 24040400 */  addiu     $a0, $zero, 0x400
/* E1800C 8024228C 0C00AB39 */  jal       heap_malloc
/* E18010 80242290 0040802D */   daddu    $s0, $v0, $zero
/* E18014 80242294 2403FFB0 */  addiu     $v1, $zero, -0x50
/* E18018 80242298 AE02006C */  sw        $v0, 0x6c($s0)
/* E1801C 8024229C AC430014 */  sw        $v1, 0x14($v0)
/* E18020 802422A0 24030140 */  addiu     $v1, $zero, 0x140
/* E18024 802422A4 AC430018 */  sw        $v1, 0x18($v0)
/* E18028 802422A8 24030384 */  addiu     $v1, $zero, 0x384
/* E1802C 802422AC 0C03A625 */  jal       func_800E9894
/* E18030 802422B0 AC430008 */   sw       $v1, 8($v0)
/* E18034 802422B4 0C03A5EE */  jal       func_800E97B8
/* E18038 802422B8 00000000 */   nop      
/* E1803C 802422BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* E18040 802422C0 8FB00010 */  lw        $s0, 0x10($sp)
/* E18044 802422C4 24020002 */  addiu     $v0, $zero, 2
/* E18048 802422C8 03E00008 */  jr        $ra
/* E1804C 802422CC 27BD0018 */   addiu    $sp, $sp, 0x18
