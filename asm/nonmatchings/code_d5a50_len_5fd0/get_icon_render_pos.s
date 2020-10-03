.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_icon_render_pos
/* DB0AC 801449AC 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB0B0 801449B0 00822024 */  and       $a0, $a0, $v0
/* DB0B4 801449B4 3C028015 */  lui       $v0, 0x8015
/* DB0B8 801449B8 8C427960 */  lw        $v0, 0x7960($v0)
/* DB0BC 801449BC 00042080 */  sll       $a0, $a0, 2
/* DB0C0 801449C0 00822021 */  addu      $a0, $a0, $v0
/* DB0C4 801449C4 8C830000 */  lw        $v1, ($a0)
/* DB0C8 801449C8 8462003C */  lh        $v0, 0x3c($v1)
/* DB0CC 801449CC ACA20000 */  sw        $v0, ($a1)
/* DB0D0 801449D0 8462003E */  lh        $v0, 0x3e($v1)
/* DB0D4 801449D4 03E00008 */  jr        $ra
/* DB0D8 801449D8 ACC20000 */   sw       $v0, ($a2)
