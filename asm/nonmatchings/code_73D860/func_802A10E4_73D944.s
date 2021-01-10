.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10E4_73D944
/* 73D944 802A10E4 24050001 */  addiu     $a1, $zero, 1
/* 73D948 802A10E8 AC8500C0 */  sw        $a1, 0xc0($a0)
/* 73D94C 802A10EC 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 73D950 802A10F0 8063F290 */  lb        $v1, %lo(gPlayerData)($v1)
/* 73D954 802A10F4 1065000B */  beq       $v1, $a1, .L802A1124
/* 73D958 802A10F8 28620002 */   slti     $v0, $v1, 2
/* 73D95C 802A10FC 10400005 */  beqz      $v0, .L802A1114
/* 73D960 802A1100 24020002 */   addiu    $v0, $zero, 2
/* 73D964 802A1104 1060000A */  beqz      $v1, .L802A1130
/* 73D968 802A1108 00000000 */   nop      
/* 73D96C 802A110C 080A844C */  j         .L802A1130
/* 73D970 802A1110 00000000 */   nop      
.L802A1114:
/* 73D974 802A1114 50620004 */  beql      $v1, $v0, .L802A1128
/* 73D978 802A1118 24020003 */   addiu    $v0, $zero, 3
/* 73D97C 802A111C 080A844C */  j         .L802A1130
/* 73D980 802A1120 00000000 */   nop      
.L802A1124:
/* 73D984 802A1124 24020002 */  addiu     $v0, $zero, 2
.L802A1128:
/* 73D988 802A1128 AC8200C0 */  sw        $v0, 0xc0($a0)
/* 73D98C 802A112C 24020002 */  addiu     $v0, $zero, 2
.L802A1130:
/* 73D990 802A1130 03E00008 */  jr        $ra
/* 73D994 802A1134 00000000 */   nop      
/* 73D998 802A1138 00000000 */  nop       
/* 73D99C 802A113C 00000000 */  nop       
