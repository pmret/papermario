.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel IncrementPlayerFP
/* 190640 80261D60 3C048011 */  lui       $a0, %hi(gPlayerData)
/* 190644 80261D64 2484F290 */  addiu     $a0, $a0, %lo(gPlayerData)
/* 190648 80261D68 90820005 */  lbu       $v0, 5($a0)
/* 19064C 80261D6C 80830006 */  lb        $v1, 6($a0)
/* 190650 80261D70 24420001 */  addiu     $v0, $v0, 1
/* 190654 80261D74 A0820005 */  sb        $v0, 5($a0)
/* 190658 80261D78 00021600 */  sll       $v0, $v0, 0x18
/* 19065C 80261D7C 00021603 */  sra       $v0, $v0, 0x18
/* 190660 80261D80 0062182A */  slt       $v1, $v1, $v0
/* 190664 80261D84 90820006 */  lbu       $v0, 6($a0)
/* 190668 80261D88 54600001 */  bnel      $v1, $zero, .L80261D90
/* 19066C 80261D8C A0820005 */   sb       $v0, 5($a0)
.L80261D90:
/* 190670 80261D90 03E00008 */  jr        $ra
/* 190674 80261D94 24020002 */   addiu    $v0, $zero, 2
