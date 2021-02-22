.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218178_69F378
/* 69F378 80218178 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 69F37C 8021817C AFBF0010 */  sw        $ra, 0x10($sp)
/* 69F380 80218180 8C82000C */  lw        $v0, 0xc($a0)
/* 69F384 80218184 0C0B1EAF */  jal       get_variable
/* 69F388 80218188 8C450000 */   lw       $a1, ($v0)
/* 69F38C 8021818C 8C43000C */  lw        $v1, 0xc($v0)
/* 69F390 80218190 3C013D23 */  lui       $at, 0x3d23
/* 69F394 80218194 3421D70A */  ori       $at, $at, 0xd70a
/* 69F398 80218198 44810000 */  mtc1      $at, $f0
/* 69F39C 8021819C 00000000 */  nop
/* 69F3A0 802181A0 E4600038 */  swc1      $f0, 0x38($v1)
/* 69F3A4 802181A4 E4600030 */  swc1      $f0, 0x30($v1)
/* 69F3A8 802181A8 8C43000C */  lw        $v1, 0xc($v0)
/* 69F3AC 802181AC 3C013FF0 */  lui       $at, 0x3ff0
/* 69F3B0 802181B0 44810000 */  mtc1      $at, $f0
/* 69F3B4 802181B4 00000000 */  nop
/* 69F3B8 802181B8 E4600034 */  swc1      $f0, 0x34($v1)
/* 69F3BC 802181BC 8C43000C */  lw        $v1, 0xc($v0)
/* 69F3C0 802181C0 3C013D4C */  lui       $at, 0x3d4c
/* 69F3C4 802181C4 3421CCCD */  ori       $at, $at, 0xcccd
/* 69F3C8 802181C8 44810000 */  mtc1      $at, $f0
/* 69F3CC 802181CC 00000000 */  nop
/* 69F3D0 802181D0 E460003C */  swc1      $f0, 0x3c($v1)
/* 69F3D4 802181D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 69F3D8 802181D8 24020002 */  addiu     $v0, $zero, 2
/* 69F3DC 802181DC 03E00008 */  jr        $ra
/* 69F3E0 802181E0 27BD0018 */   addiu    $sp, $sp, 0x18
