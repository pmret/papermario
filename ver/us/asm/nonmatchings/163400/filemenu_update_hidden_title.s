.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_update_hidden_title
/* 163FB4 80243754 3C028016 */  lui       $v0, %hi(gUIPanels)
/* 163FB8 80243758 24429D50 */  addiu     $v0, $v0, %lo(gUIPanels)
/* 163FBC 8024375C 00042140 */  sll       $a0, $a0, 5
/* 163FC0 80243760 00822021 */  addu      $a0, $a0, $v0
/* 163FC4 80243764 9083001C */  lbu       $v1, 0x1c($a0)
/* 163FC8 80243768 2862000A */  slti      $v0, $v1, 0xa
/* 163FCC 8024376C 10400008 */  beqz      $v0, .L80243790
/* 163FD0 80243770 00031040 */   sll      $v0, $v1, 1
/* 163FD4 80243774 3C038025 */  lui       $v1, %hi(D_80249CCC)
/* 163FD8 80243778 00621821 */  addu      $v1, $v1, $v0
/* 163FDC 8024377C 84639CCC */  lh        $v1, %lo(D_80249CCC)($v1)
/* 163FE0 80243780 8CE20000 */  lw        $v0, ($a3)
/* 163FE4 80243784 00431021 */  addu      $v0, $v0, $v1
/* 163FE8 80243788 03E00008 */  jr        $ra
/* 163FEC 8024378C ACE20000 */   sw       $v0, ($a3)
.L80243790:
/* 163FF0 80243790 3C028025 */  lui       $v0, %hi(D_80249CDE)
/* 163FF4 80243794 84429CDE */  lh        $v0, %lo(D_80249CDE)($v0)
/* 163FF8 80243798 8CE30000 */  lw        $v1, ($a3)
/* 163FFC 8024379C 00621821 */  addu      $v1, $v1, $v0
/* 164000 802437A0 ACE30000 */  sw        $v1, ($a3)
/* 164004 802437A4 90820000 */  lbu       $v0, ($a0)
/* 164008 802437A8 304200F7 */  andi      $v0, $v0, 0xf7
/* 16400C 802437AC 34420004 */  ori       $v0, $v0, 4
/* 164010 802437B0 03E00008 */  jr        $ra
/* 164014 802437B4 A0820000 */   sb       $v0, ($a0)
