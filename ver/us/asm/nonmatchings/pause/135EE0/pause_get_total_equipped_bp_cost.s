.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_get_total_equipped_bp_cost
/* 137B34 802447F4 0000302D */  daddu     $a2, $zero, $zero
/* 137B38 802447F8 00C0282D */  daddu     $a1, $a2, $zero
/* 137B3C 802447FC 3C088008 */  lui       $t0, %hi(gItemTable)
/* 137B40 80244800 250878E0 */  addiu     $t0, $t0, %lo(gItemTable)
/* 137B44 80244804 3C078009 */  lui       $a3, %hi(gMoveTable)
/* 137B48 80244808 24E7F060 */  addiu     $a3, $a3, %lo(gMoveTable)
/* 137B4C 8024480C 3C048011 */  lui       $a0, %hi(gPlayerData)
/* 137B50 80244810 2484F290 */  addiu     $a0, $a0, %lo(gPlayerData)
.L80244814:
/* 137B54 80244814 84820208 */  lh        $v0, 0x208($a0)
/* 137B58 80244818 1040000A */  beqz      $v0, .L80244844
/* 137B5C 8024481C 24A50001 */   addiu    $a1, $a1, 1
/* 137B60 80244820 00021140 */  sll       $v0, $v0, 5
/* 137B64 80244824 00481021 */  addu      $v0, $v0, $t0
/* 137B68 80244828 9043001A */  lbu       $v1, 0x1a($v0)
/* 137B6C 8024482C 00031080 */  sll       $v0, $v1, 2
/* 137B70 80244830 00431021 */  addu      $v0, $v0, $v1
/* 137B74 80244834 00021080 */  sll       $v0, $v0, 2
/* 137B78 80244838 00471021 */  addu      $v0, $v0, $a3
/* 137B7C 8024483C 80420012 */  lb        $v0, 0x12($v0)
/* 137B80 80244840 00C23021 */  addu      $a2, $a2, $v0
.L80244844:
/* 137B84 80244844 28A20040 */  slti      $v0, $a1, 0x40
/* 137B88 80244848 1440FFF2 */  bnez      $v0, .L80244814
/* 137B8C 8024484C 24840002 */   addiu    $a0, $a0, 2
/* 137B90 80244850 03E00008 */  jr        $ra
/* 137B94 80244854 00C0102D */   daddu    $v0, $a2, $zero
