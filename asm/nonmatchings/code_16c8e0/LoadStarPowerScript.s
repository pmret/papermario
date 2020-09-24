.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel LoadStarPowerScript
/* 1AF230 80280950 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AF234 80280954 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AF238 80280958 0080882D */  daddu     $s1, $a0, $zero
/* 1AF23C 8028095C 3C05800E */  lui       $a1, 0x800e
/* 1AF240 80280960 24A5C070 */  addiu     $a1, $a1, -0x3f90
/* 1AF244 80280964 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1AF248 80280968 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AF24C 8028096C 84A3017C */  lh        $v1, 0x17c($a1)
/* 1AF250 80280970 3C048011 */  lui       $a0, 0x8011
/* 1AF254 80280974 2484F290 */  addiu     $a0, $a0, -0xd70
/* 1AF258 80280978 00031080 */  sll       $v0, $v1, 2
/* 1AF25C 8028097C 00431021 */  addu      $v0, $v0, $v1
/* 1AF260 80280980 00021080 */  sll       $v0, $v0, 2
/* 1AF264 80280984 3C018009 */  lui       $at, 0x8009
/* 1AF268 80280988 00220821 */  addu      $at, $at, $v0
/* 1AF26C 8028098C 8022F071 */  lb        $v0, -0xf8f($at)
/* 1AF270 80280990 94830290 */  lhu       $v1, 0x290($a0)
/* 1AF274 80280994 00021200 */  sll       $v0, $v0, 8
/* 1AF278 80280998 00621823 */  subu      $v1, $v1, $v0
/* 1AF27C 8028099C A4830290 */  sh        $v1, 0x290($a0)
/* 1AF280 802809A0 84B0017A */  lh        $s0, 0x17a($a1)
/* 1AF284 802809A4 3C02802A */  lui       $v0, 0x802a
/* 1AF288 802809A8 2442C7D0 */  addiu     $v0, $v0, -0x3830
/* 1AF28C 802809AC 00108100 */  sll       $s0, $s0, 4
/* 1AF290 802809B0 02028021 */  addu      $s0, $s0, $v0
/* 1AF294 802809B4 8E040000 */  lw        $a0, ($s0)
/* 1AF298 802809B8 8E050004 */  lw        $a1, 4($s0)
/* 1AF29C 802809BC 0C00A5CF */  jal       dma_copy
/* 1AF2A0 802809C0 8E060008 */   lw       $a2, 8($s0)
/* 1AF2A4 802809C4 8E03000C */  lw        $v1, 0xc($s0)
/* 1AF2A8 802809C8 AE230084 */  sw        $v1, 0x84($s1)
/* 1AF2AC 802809CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1AF2B0 802809D0 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AF2B4 802809D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AF2B8 802809D8 24020002 */  addiu     $v0, $zero, 2
/* 1AF2BC 802809DC 03E00008 */  jr        $ra
