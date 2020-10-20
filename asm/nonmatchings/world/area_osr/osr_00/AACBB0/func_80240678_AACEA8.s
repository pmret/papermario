.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240678_AACEA8
/* AACEA8 80240678 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AACEAC 8024067C AFBF0018 */  sw        $ra, 0x18($sp)
/* AACEB0 80240680 8C82000C */  lw        $v0, 0xc($a0)
/* AACEB4 80240684 8C440000 */  lw        $a0, ($v0)
/* AACEB8 80240688 24420004 */  addiu     $v0, $v0, 4
/* AACEBC 8024068C 8C450000 */  lw        $a1, ($v0)
/* AACEC0 80240690 24420004 */  addiu     $v0, $v0, 4
/* AACEC4 80240694 8C460000 */  lw        $a2, ($v0)
/* AACEC8 80240698 24420004 */  addiu     $v0, $v0, 4
/* AACECC 8024069C 8C470000 */  lw        $a3, ($v0)
/* AACED0 802406A0 24420004 */  addiu     $v0, $v0, 4
/* AACED4 802406A4 8C430000 */  lw        $v1, ($v0)
/* AACED8 802406A8 8C420004 */  lw        $v0, 4($v0)
/* AACEDC 802406AC 306300FF */  andi      $v1, $v1, 0xff
/* AACEE0 802406B0 304200FF */  andi      $v0, $v0, 0xff
/* AACEE4 802406B4 308400FF */  andi      $a0, $a0, 0xff
/* AACEE8 802406B8 30A500FF */  andi      $a1, $a1, 0xff
/* AACEEC 802406BC 30C600FF */  andi      $a2, $a2, 0xff
/* AACEF0 802406C0 30E700FF */  andi      $a3, $a3, 0xff
/* AACEF4 802406C4 AFA30010 */  sw        $v1, 0x10($sp)
/* AACEF8 802406C8 0C046FE6 */  jal       func_8011BF98
/* AACEFC 802406CC AFA20014 */   sw       $v0, 0x14($sp)
/* AACF00 802406D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* AACF04 802406D4 24020002 */  addiu     $v0, $zero, 2
/* AACF08 802406D8 03E00008 */  jr        $ra
/* AACF0C 802406DC 27BD0020 */   addiu    $sp, $sp, 0x20
