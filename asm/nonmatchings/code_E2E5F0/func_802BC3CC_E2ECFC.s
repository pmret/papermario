.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC3CC_E2ECFC
/* E2ECFC 802BC3CC 8C820040 */  lw        $v0, 0x40($a0)
/* E2ED00 802BC3D0 3C018011 */  lui       $at, %hi(gPlayerStatus+0x2C)
/* E2ED04 802BC3D4 C420EFF4 */  lwc1      $f0, %lo(gPlayerStatus+0x2C)($at)
/* E2ED08 802BC3D8 E440000C */  swc1      $f0, 0xc($v0)
/* E2ED0C 802BC3DC 03E00008 */  jr        $ra
/* E2ED10 802BC3E0 AC400010 */   sw       $zero, 0x10($v0)
