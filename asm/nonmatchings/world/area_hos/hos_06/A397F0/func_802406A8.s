.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406A8
/* A39B88 802406A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A39B8C 802406AC AFBF0010 */  sw        $ra, 0x10($sp)
/* A39B90 802406B0 8C82000C */  lw        $v0, 0xc($a0)
/* A39B94 802406B4 0C0B1EAF */  jal       get_variable
/* A39B98 802406B8 8C450000 */   lw       $a1, ($v0)
/* A39B9C 802406BC 3C018024 */  lui       $at, 0x8024
/* A39BA0 802406C0 AC222C70 */  sw        $v0, 0x2c70($at)
/* A39BA4 802406C4 24020002 */  addiu     $v0, $zero, 2
/* A39BA8 802406C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* A39BAC 802406CC 24030001 */  addiu     $v1, $zero, 1
/* A39BB0 802406D0 3C018024 */  lui       $at, 0x8024
/* A39BB4 802406D4 AC232C6C */  sw        $v1, 0x2c6c($at)
/* A39BB8 802406D8 03E00008 */  jr        $ra
/* A39BBC 802406DC 27BD0018 */   addiu    $sp, $sp, 0x18
