.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242260_EE8810
/* EE8810 80242260 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE8814 80242264 AFBF0010 */  sw        $ra, 0x10($sp)
/* EE8818 80242268 10A00003 */  beqz      $a1, .L80242278
/* EE881C 8024226C 8C86000C */   lw       $a2, 0xc($a0)
/* EE8820 80242270 3C018024 */  lui       $at, %hi(D_8024462C)
/* EE8824 80242274 AC20462C */  sw        $zero, %lo(D_8024462C)($at)
.L80242278:
/* EE8828 80242278 3C038024 */  lui       $v1, %hi(D_8024462C)
/* EE882C 8024227C 2463462C */  addiu     $v1, $v1, %lo(D_8024462C)
/* EE8830 80242280 8C620000 */  lw        $v0, ($v1)
/* EE8834 80242284 54400003 */  bnel      $v0, $zero, .L80242294
/* EE8838 80242288 AC600000 */   sw       $zero, ($v1)
/* EE883C 8024228C 080908AA */  j         .L802422A8
/* EE8840 80242290 0000102D */   daddu    $v0, $zero, $zero
.L80242294:
/* EE8844 80242294 8CC50000 */  lw        $a1, ($a2)
/* EE8848 80242298 3C068024 */  lui       $a2, %hi(D_80244630)
/* EE884C 8024229C 0C0B551A */  jal       func_802D5468
/* EE8850 802422A0 8CC64630 */   lw       $a2, %lo(D_80244630)($a2)
/* EE8854 802422A4 24020002 */  addiu     $v0, $zero, 2
.L802422A8:
/* EE8858 802422A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* EE885C 802422AC 03E00008 */  jr        $ra
/* EE8860 802422B0 27BD0018 */   addiu    $sp, $sp, 0x18
