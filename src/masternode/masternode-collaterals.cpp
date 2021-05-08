/*
 * Copyright (c) 2020 The Pigeoncoin developers
 * Distributed under the MIT/X11 software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 *      Author: tri
 */

#include "masternode-collaterals.h"
#include <limits.h>

MasternodeCollaterals::MasternodeCollaterals(vector<Collateral> collaterals, vector<RewardPercentage> rewardPercentages) {
	this->collaterals = collaterals;
	this->rewardPercentages = rewardPercentages;
	for (auto& it : this->collaterals) {
		collateralsHeightMap.insert(make_pair(it.amount, it.height));
	}

}

CAmount MasternodeCollaterals::getCollateral(int height) const {
	for (auto& it : this->collaterals) {
		if(it.height == INT_MAX || height <= it.height) {
			return it.amount;
		}
	}
	return 0;
}

int MasternodeCollaterals::getRewardPercentage(int height) const {
	for (auto& it : this->rewardPercentages) {
		if(it.height == INT_MAX || height <= it.height) {
			return it.percentage;
		}
	}
	return 0;
}

MasternodeCollaterals::~MasternodeCollaterals() {
	this->collaterals.clear();
}

bool MasternodeCollaterals::isValidCollateral(CAmount collateralAnount) const {
	auto it = collateralsHeightMap.find(collateralAnount);
	return it != collateralsHeightMap.end();
}

bool MasternodeCollaterals::isPayableCollateral(int height, CAmount collateralAnount) const {
	if(!this->isValidCollateral(collateralAnount)) {
		return false;
	}
	int collateralEndHeight = this->collateralsHeightMap.at(collateralAnount);
	return collateralEndHeight == INT_MAX || height <= collateralEndHeight;
}
