.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_update_show_name_input
/* 163BE0 80243380 3C028016 */  lui       $v0, %hi(gWindows)
/* 163BE4 80243384 24429D50 */  addiu     $v0, $v0, %lo(gWindows)
/* 163BE8 80243388 00042140 */  sll       $a0, $a0, 5
/* 163BEC 8024338C 00822021 */  addu      $a0, $a0, $v0
/* 163BF0 80243390 9083001C */  lbu       $v1, 0x1c($a0)
/* 163BF4 80243394 14600005 */  bnez      $v1, .L802433AC
/* 163BF8 80243398 28620010 */   slti     $v0, $v1, 0x10
/* 163BFC 8024339C 90820000 */  lbu       $v0, ($a0)
/* 163C00 802433A0 304200FB */  andi      $v0, $v0, 0xfb
/* 163C04 802433A4 A0820000 */  sb        $v0, ($a0)
/* 163C08 802433A8 28620010 */  slti      $v0, $v1, 0x10
.L802433AC:
/* 163C0C 802433AC 10400008 */  beqz      $v0, .L802433D0
/* 163C10 802433B0 00031040 */   sll      $v0, $v1, 1
/* 163C14 802433B4 3C038025 */  lui       $v1, %hi(D_80249BDC)
/* 163C18 802433B8 00621821 */  addu      $v1, $v1, $v0
/* 163C1C 802433BC 84639BDC */  lh        $v1, %lo(D_80249BDC)($v1)
/* 163C20 802433C0 8CC20000 */  lw        $v0, ($a2)
/* 163C24 802433C4 00431021 */  addu      $v0, $v0, $v1
/* 163C28 802433C8 03E00008 */  jr        $ra
/* 163C2C 802433CC ACC20000 */   sw       $v0, ($a2)
.L802433D0:
/* 163C30 802433D0 3C028025 */  lui       $v0, %hi(D_80249BFA)
/* 163C34 802433D4 84429BFA */  lh        $v0, %lo(D_80249BFA)($v0)
/* 163C38 802433D8 8CC30000 */  lw        $v1, ($a2)
/* 163C3C 802433DC 00621821 */  addu      $v1, $v1, $v0
/* 163C40 802433E0 ACC30000 */  sw        $v1, ($a2)
/* 163C44 802433E4 90820000 */  lbu       $v0, ($a0)
/* 163C48 802433E8 304200F7 */  andi      $v0, $v0, 0xf7
/* 163C4C 802433EC 03E00008 */  jr        $ra
/* 163C50 802433F0 A0820000 */   sb       $v0, ($a0)
